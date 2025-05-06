//BT27.cpp
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> input_vector(int n)
{
	vector<vector<int>> v(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}

	return v;
}

void tichchap(vector<vector<int>>&v, vector<vector<int>>&w)
{
	int n=v.size();
	int m=w.size();
	//int index;
	//index=n/m;
	for(int hang=0;hang<n;hang++)
	{
		for(int cot=0;cot<n;cot++)
		{
			v[hang][cot]*=w[hang%m][cot%m];
			cout<<v[hang][cot]<<" ";
		}
		cout<<endl;
	}
	
}

int main()
{
	int n; cin>>n;
	vector<vector<int>> v=input_vector(n);
	int m; cin>>m;
	vector<vector<int>> w=input_vector(m);
	tichchap(v,w);

}
