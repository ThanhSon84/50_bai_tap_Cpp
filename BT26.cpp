//BT26.cpp
//Ap dung 2 con tro
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void merge(vector<int>& a)
{
	//tao bien dem so lan merge
	long long count=0;
	//DP voi 2 pointer 2 dau
	int left=0;int right=a.size()-1;
	//Duyet tu 0 den n-1
	while(left<right)
	{
		if(a[left]==a[right])
		{
			left++;
			right--;
			continue;
		}
		else
		{
			//gop gia tri ben trai
			//int merge_left=a[left]+a[left+1];
			//gop gia tri ben trai
			//int merge_right=a[right]+a[right-1];
			//chon gia tri merge
			if(a[left]<a[right])
			{
				a[left+1]+=a[left];
				left++;
			}
			else
			{
				a[right-1]+=a[right];
				right--;
			}
			count++;
		}
	}
	cout<<count<<endl;

}

int main()
{
	int test; cin>>test;
	while(test--)
	{
		int n; cin>>n;
		vector<int> a(n);
		//nap vector
		for(int& it: a)
		{
			cin>>it;
		}
		//merge
		merge(a);
		//in ra so lan merge
	}
}
