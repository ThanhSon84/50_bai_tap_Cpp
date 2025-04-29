//BT20.cpp
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

struct Contestant{
	string Name;
	string Date_of_Birth;
	double Mark1, Mark2, Mark3;
};


int main(){
	Contestant ts;
	getline(cin,ts.Name);
	getline(cin,ts.Date_of_Birth);
	cin>>ts.Mark1>>ts.Mark2>>ts.Mark3;
	cout<<ts.Name<<" "<<ts.Date_of_Birth<<" "<<fixed<<setprecision(1)<<(ts.Mark1+ts.Mark2+ts.Mark3);
	
}
