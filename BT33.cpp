//BT33.cpp
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void input_vect(vector<int>& vec, int n)
{
	for(int i=0;i<n;i++)
	{
		/*
		int elements;
		cin>>elements;
		vec.push_back(elements);
		*/
		int j;cin>>j;
		vec.push_back(j);
	}
	sort(vec.begin(), vec.end(), greater<int>());//sap xep giam dan
}

void output_vect(vector<int>& vec, const int& n)
{
	int left=0;int right=n-1;
	while(left<right)
	{
		cout<<vec[left]<<" "<<vec[right]<<" ";
		left++;
		right--;
	}
	if(left==right)//truong hop bi sot khong in
	{
		cout<<vec[left];

	}
	cout<<endl;
}

int main()
{
	int testcases; cin>>testcases;
	while (testcases--)
	{
		int n; cin>>n;
		vector<int> v;
		input_vect(v,n);
		output_vect(v,n);
	}
}
