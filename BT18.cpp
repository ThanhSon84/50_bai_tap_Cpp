//BT18.cpp
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main(){
	string str;
	cin>>str;
	for(char& c: str){
		c=tolower(c);
	}
	for(char& p: str){
		if(p!='a'&&p!='e'&&p!='i'&&p!='o'&&p!='u'&&p!='y') cout<<"."<<p;
	}

}
