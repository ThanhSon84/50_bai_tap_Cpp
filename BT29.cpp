#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(){
	int testcases;
	cin>>testcases;
	cin.ignore();
	while(testcases--)
	{
		long long res=0;
		
		string input;
		getline(cin,input);
		string calc;
		for(char num:input)
		{
			if(isdigit(num))
			{
				calc+=num;
			}
			else
			{
				if(!calc.empty())
				{	
					res+=stoi(calc);
					calc.clear();
				}
			}
		}

		if(!calc.empty())
		{
			res+=stoi(calc);
			calc.clear();
		}
		
		cout<<res<<endl;
	}
}
