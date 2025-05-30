//BT49.cpp-doc thanh dong
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string lower_str(string& str)
{
	for(char& c: str)
	{
		c=tolower(c);
	}
	return str;
}


int main()
{
	ifstream input;
	input.open("VANBAN.in");
	set<string> collected_word;
	string line;
	
	while (getline(input,line))
	{
		stringstream ss(line);
		string word;
		while(ss>>word)
		{		
			word=lower_str(word);
			collected_word.insert(word);
		}
	}

	for(auto it: collected_word)
	{
		cout<<it<<endl;
	}

}
