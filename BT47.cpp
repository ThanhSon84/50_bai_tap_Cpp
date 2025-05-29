//BT47.cpp
//Muc tieu la dem cac xau con 100
//sau khi loai bo 100 dem tiep
//lap den khi khong con 
//PA dem tu phai -> trai den khi  gap ki tu 1 dem so ki tu 00 phia sau
//du cat chuoi thi dem (ti so Sl so 0 gap 2 lan sl so 1)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void count_substr(const string& str0)
{
	int count=0;
	int count0=0;
	//int count1=0;
	for(int i=str0.size()-1; i>=0;i--)
	{
		if(str0[i]=='0') count0++;
		else
		{
			//count1++;
			if(count0>=2)
			{
				//count1--;
				count0-=2;
				count++;
			}
		}
	}
	cout<<count*3<<endl;//do dai chuoi la 3
}

int main()
{
	int test_case;
	cin>>test_case;
	cin.ignore();
	while(test_case--)
	{
		string str;
		getline(cin,str);
		count_substr(str);
	}
}
