//BT11.cpp
#include<iostream>
#include<array>
#include<cmath>
#include<algorithm>

using namespace std;

void cycle_Elements(int* a, int n, int d){
	int Reshaping_array[n];
	for(int i=0;i<n-d;i++){
		Reshaping_array[i]=a[i+d];
	}
	for(int i=0;i<d;i++){
		Reshaping_array[n-d+i]=a[i];
	}
	for(int i=0;i<n;i++){
		cout<<Reshaping_array[i]<<" ";
	}
	cout<<endl;

}

int  main(){
	int test; cin>>test;
	while(test--){
		int Size_arr;
		int d;
		cin>>Size_arr>>d;
		int Arr[Size_arr];
		for(int i=0;i<Size_arr;i++){
			cin>>Arr[i];
		}
		cycle_Elements(Arr,Size_arr,d);
	}
	return 0;

}
