//BT31.cpp
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void input_vect(vector<int>& vect, int num_elements,set<int>& uni_set)
{
	while(num_elements--)
	{
		int input;
		cin>>input;
		vect.push_back(input);
		uni_set.insert(input);
	}

}

void intersect_vect(vector<int>& vecta, int numa_elements,vector<int>& vectb, int numb_elements,vector<int>& vectc)
{
	for(int i=0;i<numa_elements;i++)
	{
		int val=vecta[i];
		auto it=find(vectb.begin(),vectb.end(),val);
		if(it != vectb.end())
		{
			vectc.push_back(val);
		}
	}
	sort(vectc.begin(),vectc.end());
}

int main()
{
	int testcases; cin>>testcases;
	while(testcases--)
	{
		vector<int> a, b, intersect;
		set<int> uni;
		int n,m; cin>>n>>m;
		input_vect(a,n,uni);
		input_vect(b,m,uni);
		intersect_vect(a,n,b,m,intersect);
		for(auto it:uni)
		{
			cout<<it<<" ";
		}
		cout<<endl;
		for(auto pt:intersect)
		{
			cout<<pt<<" ";
		}


	}
}
