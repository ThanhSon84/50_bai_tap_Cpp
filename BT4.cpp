//BT4.cpp
#include<iostream>
#include<math.h>

using namespace std;

int sochuso(int n){
	if(n<10) return 0;
	int count=0;
	while(n!=0){
		count++;
		n/=10;
	}
	if(count%2==0) return 1;
	else return 0;
}

int ktra(int n){
	int odd=0, even=0;
	if(sochuso(n)){
		while(n){
			if((n%10)%2==0)even++;
			else odd++;
			n/=10;
		}
	}
	if(odd==even) return 1;
	else return 0;
	
}

int main(){
	//nhap so can kiem tra
	int num;
	cin>>num;
	long long NUM=pow(10,num)-1;
	int count=0;
	for(long long i=10;i<=NUM;i++){
		if(ktra(i)) {
			count++;
			if(count<=10){
				cout<<i<<" ";
			}
			if(count==11){
				cout<<endl<<i<<" ";
				count-=10;
			}
		}
	}
	return 0;
}

