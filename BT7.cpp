//BT7.cpp
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

void inUNT(long long m){
	for(long long i=2;i<=sqrt(m);i++){
		if(m%i==0){
			while(m%i==0){
				cout<<i<<" ";
				m/=i;
			}
		}
	}
	if(m!=1) cout<<m<<endl;
}



int main(){
	int test;
	cin>>test;
	while(test--){
		long long n;
		cin>>n;
		inUNT(n);
	}
	return 0;
}
