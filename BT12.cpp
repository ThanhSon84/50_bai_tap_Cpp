//BT12.cpp
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>//dung khai bao pair

using namespace std;

void input_Matrix(vector<vector<int>>& a, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
}

void replace_Elements(vector<vector<int>>& a, int m, int n){
	int i,j;
	vector<pair<int,int>> pos;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1){
				pos.push_back({i,j});
			}
		}
	}
	for (const auto& p:pos){
		for(i=0;i<m;i++){
			a[i][p.second]=1;
		}
		for(j=0;j<n;j++){
			a[p.first][j]=1;
		}
	}

}

void print_Matrix(vector<vector<int>>& a, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int test; cin>>test;
	while(test--){
		int m, n; cin>>m>>n;
		vector<vector<int>> a(m,vector<int>(n));
		input_Matrix(a,m,n);
		replace_Elements(a,m,n);
		print_Matrix(a,m,n);
	}
	return 0;

}
