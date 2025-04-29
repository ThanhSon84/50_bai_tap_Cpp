//BT19.cpp
#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

void input_Ele(vector<string>& str,int n){
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
}

void output_Ele(const vector<string>& str){
	set<char> s;
	for(const string& i: str){
		for(char c: i){
			s.insert(c);
		}
	}
	for(char c: s){
		cout<<c<<" ";
	}
	cout<<endl;
}

int main(){
	int test; cin>>test;
	while(test--){
		int n; cin>>n;
		vector<string> str(n);
		input_Ele(str,n);
		output_Ele(str);

	}

	return 0;
}
