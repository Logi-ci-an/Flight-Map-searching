#pragma once
#include<utility>
#include<set>
#include<map>
#include"City.h"
#include<fstream>
#include<vector>
using namespace std;
# define ABS_PATH "C:\\Users\\Ahmed kamal\\Github\\Flight_map\\Flight-Map-searching\\flight_map\\"
class FileManager
{
public:
	void GetPairs(string File, vector<pair<string,string>>* F) {
		ifstream file;
		file.open(ABS_PATH + File + ".txt", ios::in);
		//perror("the Error");
		string result;
		while (getline(file, result)) {
			int comma = result.find(',');
			pair<string,string>p1;
			string C1 = result.substr(0, comma);
			string C2 = result.substr(comma + 2);
			p1.first = C1;
			p1.second = C2;
			F->push_back(p1);
		}
	}


	void GetCitys(string File, map<string, City*>&F) {
		ifstream file;
		file.open(ABS_PATH + File + ".txt", ios::in);
	//	perror("the Error");
		string result;
		while (getline(file, result)) {
			City* C1 = new City(result);
			F[result] = C1;
		}

	}
};

