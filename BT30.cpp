//BT30.cpp
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>


using namespace std;

int main()
{
	int testcases; cin>>testcases;
	cin.ignore();
	while(testcases--)
	{
		long long sum=0;
		string input;
		string text="";
		getline(cin, input);
		for(char ch:input)
		{
			if(isdigit(ch))
			{
				sum+=(ch-'0');
			}
			else
			{
				text+=ch;
			}
		}
		sort(text.begin(),text.end());
		text+=(sum+'0');
		for(char t:text)
		{
			cout<<t;
		}
		cout<<endl;
	}
}


