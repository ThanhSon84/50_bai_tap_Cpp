//BT3.cpp
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	//nhap du lieu
	int x;
	cin>>x;
	long long res=0;
	long long tich=1;
	for(int i=1;i<=x;i++){
		tich=tich*i;
		res+=tich;
	}
	cout<<res<<endl;
	return 0;
}
