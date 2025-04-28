//BT15.cpp
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<array>
#include<utility>

using namespace std;

void input_Map(map<int,int>& m, int n){
	for(int i=0;i<n;i++){
		int tmp;cin>>tmp;
		m[tmp]++;//dem so lan xuat hien cua p.tu i
	}
}

void print_repetition_Elements(map<int,int>& m, int n){
	int sum=0;
	for(const auto element: m){
		if(element.second>1) sum+=element.second;
	}
	cout<<sum<<endl;
}

int main(){
	int test; cin>>test;
	while(test--){
		int n;cin>>n;
		map<int,int> m;
		input_Map(m,n);
		print_repetition_Elements(m,n);
	}
	return 0;
}
