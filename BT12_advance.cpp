//BT12_advance.cpp
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void input_Mat(vector<vector<int>>& a, int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
}

void find_replace_print(vector<vector<int>>& a, int m,int n){
	vector<bool> row(m,false), col(n,false);
	//tao 2 vector danh dau hang, cot
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				row[i]=true;
				col[j]=true;
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(row[i]||col[j]){
				a[i][j]=1;
			}
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int test; cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		vector<vector<int>> a(m,vector<int>(n));
		input_Mat(a,m,n);
		find_replace_print(a,m,n);
	}
	return 0;
}
