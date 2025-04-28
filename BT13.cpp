//BT13.cpp
#include<iostream>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

void input_Matrix(vector<vector<int>>& a, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
}

void find_Edge_print(vector<vector<int>>& a, int n){
	int i,j;;
	vector<bool> row(n,false);
	vector<bool> col(n,false);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0||i==n-1) row[i]=true;
			if(j==0||j==n-1) col[j]=true;
		}
	}

	//print
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(row[i]||col[j]) cout<<a[i][j]<<" ";
			else cout<<" "<<" ";
		}
		cout<<endl;
	}

}

int main(){
	int test; cin>>test;
	while(test--){
		int n; cin>>n;
		vector<vector<int>> a(n,vector<int>(n));
		input_Matrix(a,n);
		find_Edge_print(a,n);

	}
	return 0;
}
