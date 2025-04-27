//BT9_rev.cpp
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<limits.h>

using namespace std;

void min_dist(int* a, int n){
	int min_val=INT_MAX;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			min_val=min(min_val,abs(a[i]-a[j]));
		}
	}
	cout<<min_val<<endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int size;
		cin>>size;
		int* arr=new int[size];
		for(int i=0;i<size;i++){
			cin>>arr[i];
		}
		min_dist(arr,size);
		delete[]arr;
	}
	return 0;
}
