//BT22.cpp
#include<iostream>
#include<numeric>


using namespace std;

long long ad_gcd(long long a, long long b)
{
	while(b!=0)
	{
		long long tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;

}

class Phanso
{
public:
	long long tu;
	long long mau;

	//ham khoi tao mac dinh
	Phanso()
	{
		tu=0;
		mau=1;
	}

	//ham khoi tao co tham so
	Phanso(long long t, long long m)
	{
		tu=t;
		if(m==0)
		{
			cout<<"Khong tao duoc phan so!";
			exit(1);
		} 
		else
		{
			mau=m;
		}

	}

	//ham toi gian
	void toigian()
	{
		int UCLN=ad_gcd(tu,mau);
		if(mau==0)
		{
		 	cout<<"Khong tao duoc phan so!";
			exit(1);
		}
		else
		{
			if(tu==0) cout<<0<<endl;
			else
			{
				if(tu==mau) cout<<1<<endl;
				else cout<<tu/UCLN<<"/"<<mau/UCLN<<endl;
			}
		}
	}
};

int main()
{
	long long a, b;
	cin>>a>>b;
	Phanso ps(a,b);
	ps.toigian();
}
