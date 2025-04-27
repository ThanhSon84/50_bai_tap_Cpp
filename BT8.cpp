//BT8.cpp
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

constexpr int MAX=1e6+1;//khai bao constexpr cho bien MAX de xac dinh la int
int nt[MAX];

void sieve(){
	nt[0]=0;
	nt[1]=0;
	for(int i=2;i<MAX;i++){
		nt[i]=1;
	}
	for(int i=1;i<=sqrt(MAX);i++){
		if(nt[i]){
			for(int j=i*i;j<MAX;j+=i){
				nt[j]=0;
			}
		}
	}
}

void in3Uoc(int n){
	int can;
	can=sqrt(n);
	if(can*can==n && nt[can]==1) cout<<n<<" ";
}

int main(){
	sieve();
	int test;
	cin>>test;
	while(test--){
		int input;
		cin>>input;
		for(int i=1;i<=input;i++){
			in3Uoc(i);
		}
		cout<<endl;
	}
	return 0;
	
}
