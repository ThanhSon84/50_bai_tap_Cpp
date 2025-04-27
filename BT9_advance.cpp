//BT9_advance.cpp
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<math.h>

using namespace std;

void inMin_Dist(int* a, int n){
	int min_val=INT_MAX;
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		min_val=min(min_val,(a[i+1]-a[i]));
	}
	cout<<min_val<<endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int Size_Arr;
		cin>>Size_Arr;
		int* Arr=new int[Size_Arr];
		for(int i=0;i<Size_Arr;i++){
			cin>>Arr[i];
		}
		inMin_Dist(Arr,Size_Arr);

		delete[]Arr;
	}
	return 0;
}
