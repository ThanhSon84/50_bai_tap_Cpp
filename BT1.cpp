//BT1.cpp
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	//nhap bo test
	int test;
	cin>>test;
	while(test--){
		int x;
		cin>>x;
		long long kq;
		kq=1ll*x*(x+1)/2;
		cout<<kq<<endl;
	}
	return 0;
}
