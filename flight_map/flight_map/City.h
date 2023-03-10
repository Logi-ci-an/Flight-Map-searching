#pragma once
#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;
class City
{
private:
	string Name;
	bool Visited;
	int Num_of_cities_connected_with_it;
public:
	City(string Namen) {
		Name = Namen;
		Visited = false;
		Num_of_cities_connected_with_it = 0;
	}
	City(City& city) {
		Name = city.Name;
		Visited = city.Visited;
		Num_of_cities_connected_with_it = city.Num_of_cities_connected_with_it;
	}
	City() {
		Name = "";
		Visited = false;
		Num_of_cities_connected_with_it = 0;
	}
	string NAME() {
		return this->Name;
	}
	void Visit() {
		this->Visited = true;
	}
	void unVisit() {
		this->Visited = false;
		this->Num_of_cities_connected_with_it = 0;
	}
	bool isVisited() {
		return this->Visited;
	}
	static void UnVisit_ALL(map<string,City*>m1) {
		for (auto iterator : m1) {
			iterator.second->unVisit();
		}
	}

	int Num_of_cities_with_it() {
		return this->Num_of_cities_connected_with_it;
	}
	void increment_Num_of_cities_with_it() {
		this->Num_of_cities_connected_with_it++;
		return;
	}

};

