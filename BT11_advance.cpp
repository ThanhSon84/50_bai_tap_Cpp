//BT11_advance.cpp
#include<iostream>
#include<cmath>
#include<algorithm>
#include<array>

using namespace std;

void cycling_Elements(int* a, int n, int d){
	reverse(a,a+n);//nghich dao 0~n-1
	reverse(a+n-d,a+n);//ngich dao doan n-d~n-1 (d ptu)
	reverse(a,a+n-d);//nghich dao doan 0~n-1-d
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}


	cout<<endl;

}

int main(){
	int test; cin>>test;
	while (test--){
		int Size_Array;
		int d;
		cin>>Size_Array>>d;
		int Arr[Size_Array];
		for(int i=0;i<Size_Array;i++){
			cin>>Arr[i];
		}
		cycling_Elements(Arr,Size_Array,d);
	}
	return 0;
}
