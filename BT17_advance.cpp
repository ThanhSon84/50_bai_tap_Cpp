//BT17_advance.cpp
#include<iostream>
#include<cmath>
#include<string>


using namespace std;

void count_Substr(const string& str){
	int mark[26]={0};//26 chu cai a den z
	int res=0;
	for(char c: str){
		mark[c-'a']++;//dem so lan ky tu xuat hien trong str
	}
	for(int i=0;i<26;i++){
		if(mark[i]){
			res+=mark[i];//phan tu don
			res+=(mark[i]/2)*(mark[i]-1);//to hop 2 cua mark[i] ptu
		}
	}
	cout<<res<<endl;
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
