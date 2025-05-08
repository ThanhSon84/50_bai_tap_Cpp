//BT28.cpp
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void hoanvi(vector<int>& v)
{
	int N=v.size();
	cout<<"v.size()"<<N<<endl;
	int check=0;
	//int index=0;
	for(int i=N-2;i>=0&&!check;i--)//dung dieu kien check thoat for
	{
		for(int j=i+1;j<N;j++)
		{
			if(v[i]>v[j])
			{
				swap(v[i],v[j]);
				check=1;
				break;
			}
		}
	}
	if(check)
	{
		for(int& it:v)
		{
			cout<<it;
		}
		cout<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}

}

int main()
{
	int test; cin>>test;
	while(test--)
	{
		string s;
		cin.ignore();
		std::getline(std::cin,s);
		//nhap vao tu string vao vector
		vector<int> v;
		//stringstream ss(s);
		//int element;
		for(char element: s)
		{
			v.push_back(element-'0');
		}

		hoanvi(v);
	}
	return 0;
}
