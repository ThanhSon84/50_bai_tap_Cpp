//BT48.cpp
#include<iostream>
#include<fstream>
#include<map>

using namespace std;

int main()
{
	ifstream input;
	input.open("DATA.in");
	map<int,int> tansuat;
	int so;
	while(input>>so)
	{
		tansuat[so]++;
	}
	for(auto it=tansuat.begin();it!=tansuat.end();++it)
		cout<<it->first<<" "<<it->second<<endl;
}
