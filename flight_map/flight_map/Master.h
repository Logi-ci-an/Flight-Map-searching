#pragma once
#include<iostream>
#include<string>
#include"City.h"
#include<utility>
#include<map>
#include<set>
#include<vector>
#include"FileManager.h"

#define FLIST_FILE "FFile"
#define RLIST_FILE "RFile"
#define City_FILE "CityFile"
using namespace std;
class Master
{
private:
	map<string,City*>CList;
	//vector<pair<City*, City*>>*Flist;
	//vector<pair<City*, City*>>*Rlist;
	vector<pair<string, string>>* Flist;
	vector<pair<string, string>>* Rlist;
	FileManager* FM;



	//algorithm backtraking

//using recursion part
	bool Recursion_technique(string origin, string dest, vector<string>& result) {
		if (origin == dest) {
			result.push_back(origin);
			return true;
		}
		if (this->CList[origin]->isVisited()) {
			return false;
		}
		City* ptr = this->GetNext(origin);
		this->CList[origin]->Visit();
		result.push_back(origin);
		while (ptr != nullptr) {
			bool flag = Recursion_technique(ptr->NAME(), dest, result);
			if (flag) {
				return true;
			}
			else {

			}
			ptr = this->GetNext(origin);
		}
		result.pop_back();
		return false;
	}

public:

	//file management section
	Master() {
		FM->GetCitys(City_FILE, this->CList);
		Flist = new vector<pair<string, string>>;
		FM->GetPairs(FLIST_FILE,Flist);
		Rlist = new vector<pair<string, string>>;
		FM->GetPairs(RLIST_FILE, Rlist);

	}
	void print() {
	/*	vector<pair<string,string>>flist = *Flist;
		for (auto i : flist) {
			cout<< i.first<< " ";
			cout << i.second<< endl;
		}
		cout << " **** " << endl;
		vector<pair<string, string>>rlist = *Rlist;
		for (auto i : rlist) {
			cout << i.first << " ";
			cout << i.second << endl;
		}*/

		cout << " **** Out Cities we serve : " << endl;
		for (auto i : this->CList) {
			cout <<"               #***#  "   << i.first <<endl;
		}
		cout <<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	}
	//getting next city

	City* GetNext(string city) {
		int counter = 0;
		for (auto it : *Flist) {
			if (it.first == city) {
				counter++;
				if (counter-1 == this->CList[city]->Num_of_cities_with_it()) {
					//increment city count
					this->CList[city]->increment_Num_of_cities_with_it();
					//return your city
					return this->CList[it.second];
				}
			}
		}
		return nullptr;
	}
	//main function
	bool FindWay(string origin, string dest, vector<string>& result) {
		cout << " *********** ";
		cout << " Origin : " << origin << "    Destination : " << dest << endl;
		auto i1 = this->CList.find(origin);
		auto i2 = this->CList.find(dest);
		if (i1 == this->CList.end() || i2 == this->CList.end()) {
			cout << "  Error : your inputs are wrong or not served in our system ," << endl;
			return false;
		}
		if (origin == dest) {
			cout << "You are already in the same city" << endl;
			return false;
		}
		City::UnVisit_ALL(this->CList);
		bool x= this->Recursion_technique(origin, dest, result);
		if (!x) {
			cout << " NO Way " << endl;
		}
		return x;
	}

	void Tester() {
		for (auto it : *this->Rlist) {
			vector<string>result;
			if (this->FindWay(it.first, it.second, result)) {
				for (auto i : result) {
					cout << i << "         ";
				}
			}
			cout << endl;
		}
	}

	~Master() {


		delete Flist;


		delete Rlist;


		for (auto i : this->CList) {
			delete i.second;
		}
	}
};

