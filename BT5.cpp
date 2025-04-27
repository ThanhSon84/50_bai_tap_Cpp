//BT5.cpp
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

void check(const string &a){
	int pos_start=a.length()-2;
	//cout<<"length="<<a.length()<<endl;
	string test=a.substr(2,pos_start);
	if(test=="86") cout<<1<<endl;
	else cout<<0<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string input;
		cin>>input;
		check(input);
	}
	return 0;
}
