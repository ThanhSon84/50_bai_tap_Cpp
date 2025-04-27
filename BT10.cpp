//BT10.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<array>
#include<algorithm>

using namespace std;

void plus_missing_Element(int* a,int n){
	sort(a,a+n);
	if(a[0]>1){ //khong co phan tu am hoac so 0_can trai
		cout<<1<<endl;
		return;
	}
	int Inner_check=0;//kiem tra co phat sinh gia tri trong day
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]>1 && a[i]>=0) {
			cout<<a[i]+1<<endl;
			Inner_check=1;
			break;
		}
	}
	if(!Inner_check && a[n-1]>=0) cout<<a[n-1]+1<<endl;//khong co phan tu trong day_can phai
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int Size_Array;
		cin>>Size_Array;
		int Arr[Size_Array];
		for(int i=0;i<Size_Array;i++){
			cin>>Arr[i];
		}
		plus_missing_Element(Arr,Size_Array);
	}
	return 0;
}
