//BT42.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cctype>
#include<cmath>

using namespace std;

struct Student
{
	string MS;
	string Hoten;
	string Lop;
	string Email;

};


void nhap_Thong_tin(struct Student& sv)
{
	getline(cin,sv.MS);
	getline(cin,sv.Hoten);
	getline(cin,sv.Lop);
	getline(cin,sv.Email);
}

string xu_ly_Khoang_trong_Do_dai(string& dactinh)
{
	dactinh.remove(erase(dactinh.begin(),dactinh.end(),' '),dactinh.end());
	if(dactinh.size()>15) dactinh=dactinh.substr(0,15);
	return dactinh;
}

string xu_ly_Hoten(string& Hoten)
{
	if(Hoten.size()>100) Hoten=Hoten.substr(0,100);
	return Hoten;
}

bool Lop_MS(const Student& a, const Student& b)
{
	if(a.Lop!=b.Lop) return a.Lop<b.Lop;
	else
		return a.MS<b.MS;
}


int main()
{
	int so_Sv;
	cin>>so_Sv;
	vector<Student> Sv_theo_Lop;
	cin.ignore();
	while(so_Sv--)
	{
		struct Student sv1;
		nhap_Thong_tin(sv1);
		xu_ly_Khoang_trong_Do_dai(sv1.MS);
		xu_ly_Hoten(sv1.Hoten);
		xu_ly_Khoang_trong_Do_dai(sv1.Lop);
		xu_ly_Khoang_trong_Do_dai(sv1.Email);
		Sv_theo_Lop.push_back(sv1);
	}

	sort(Sv_theo_Lop.begin(),Sv_theo_Lop.end(),Lop_MS);

	for(auto& i: Sv_theo_Lop)
	{
		cout>>i.MS>>" ">>i.Hoten>>" ">>i.Lop>>" ">>i.Email>>endl;
	}
}
