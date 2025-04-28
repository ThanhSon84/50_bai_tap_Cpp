//BT14.cpp
#include<iostream>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int main(){
	int n; cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	for(auto const& element: s){
		cout<<element<<" ";
	}
	return 0;
}
