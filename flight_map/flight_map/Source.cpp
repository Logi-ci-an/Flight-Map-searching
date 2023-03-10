#include"Master.h"
#include"City.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
int main() {
	Master M;
	M.print();
	//string input;
	//cin >> input;
	//City* c1=M.GetNext(input);
	//cout << c1->NAME() << endl;
	//cin >> input;
	//c1 = M.GetNext(input);
	//cout << c1->NAME() << endl;
	//cin >> input;
	//c1 = M.GetNext(input);
	//cout << c1->NAME() << endl;
	//string input;
	//string output;
	//getline(cin, input);
	//getline(cin,output);
	//vector<string>result;
	//cout << M.Recursion_technique(input, output,result);
	//for (auto i : result) {
	//	cout << i << endl;
	//}
	M.Tester();

}