//BT23.cpp
#include<iostream>
#include<numeric>

using namespace std;

long long ucln(long long a, long long b)
{
	while(b!=0)
	{
		long long tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}

class phanso
{
public:
	long long tu, mau;
	//ham khoi tao mac dinh
	phanso(): tu(0), mau(1){};
	//ham khoi tao co tham so
	phanso(long long t, long long m)
	{
		if(m==0)
		{
			cout<<"Khong xac dinh";
			exit(1);
		}
		else
		{
			tu=t;
			mau=m;
		}
	}

	void toigian()
	{
		long long ts=ucln(tu, mau);
		tu /= ts;
		mau /= ts;
	}

	phanso cong_phanso(phanso& ps2)
	{
		long long ts=tu*ps2.mau+ps2.tu*mau;
		long long ms=mau*ps2.mau;
		phanso kq(ts, ms);
		kq.toigian();
		return kq;

	}

};

int main()
{
	long long t1,m1,t2,m2;
	cin>>t1>>m1>>t2>>m2;
	phanso ps1(t1,m1);
	ps1.toigian();
	phanso ps2(t2,m2);
	ps2.toigian();
	phanso kq=ps1.cong_phanso(ps2);
	cout<<kq.tu<<"/"<<kq.mau;
}
