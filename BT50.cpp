//BT50.cpp-tim phan tu trong set
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<cctype>
#include<iostream>
#include<fstream>

using namespace std;


int main()
{
	map<string,int> collected_word;
	ifstream input;
	input.open("DATA1.in");
	string line;
	while(getline(input,line))
	{
		stringstream ss(line);
		string word;
		while(ss>>word)
		{
			collected_word[word]++;
		}
	}
	input.close();
	input.open("DATA2.in");
	while(getline(input,line))
	{
		stringstream ss(line);
		string word;
		while(ss>>word)
		{
			collected_word[word]++;
		}
	}
	input.close();
	for(auto it=collected_word.begin();it!=collected_word.end();++it)
	{
		cout<<it->first<<" ";
	}
	cout<<endl;
	for(auto it=collected_word.begin();it!=collected_word.end();++it)
	{
		if(it->second>=2) cout<<it->first<<" ";
	}
	cout<<endl;

}
