//BT17.cpp
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

void count_Substr(const string& str){
	int count=str.length();
	for(int i=0;i<str.length()-1;i++){
		for(int j=i+1;j<str.length();j++){
			if(str[i]==str[j])count++;
		}
	}
	cout<<count<<endl;


}

int main(){
	int test; cin>>test;
	while(test--){
		string str;
		cin>>str;
		count_Substr(str);
	}
	return 0;
}

