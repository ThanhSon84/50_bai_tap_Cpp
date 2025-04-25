//BT2.cpp
#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	//nhap bo test
	int test;
	cin>>test;
	while(test--){
		char kitu;
		cin>>kitu;
		if(isupper(kitu)) cout<<(char)tolower(kitu);
		else cout<<(char)toupper(kitu);
		cout<<endl;
	}
	return 0;
}
