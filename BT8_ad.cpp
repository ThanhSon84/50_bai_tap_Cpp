//BT8_advance.cpp
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

const int MAX=1000001;
int nt[MAX];

void sieve(){
	for(int i=0;i<MAX;i++){
		nt[i]=1;
	}
	nt[0]=0;
	nt[1]=0;
	for(int i=2;i<=sqrt(MAX);i++){
		if(nt[i]){
			for(int j=i*i;j<MAX;j+=i){
				nt[j]=0;
			}
		}
	}
}

void in3UNT_ad(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(nt[i]){
			int bp=i*i;
			if(bp<=n) cout<<bp<<" ";
		}
	}
	cout<<endl;
}

int main(){
	sieve();
	int test; cin>>test;
	while(test--){
		int input;
		cin>>input;
		in3UNT_ad(input);
	}
	return 0;
}
