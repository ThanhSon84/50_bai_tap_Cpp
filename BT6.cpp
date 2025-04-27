//BT6.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

void innt(int n){
	int nt=1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			nt=0;
			break;
		}
	}
	if(nt) cout<<n<<" ";
}

int main(){
	int a, b;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		innt(i);
	}

	return 0;

}
