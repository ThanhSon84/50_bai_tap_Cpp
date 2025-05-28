//BT44.cpp
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>


using namespace std;

struct SV
{
	string MS;
	string Hten;
	string Lop;
	string Email;
	pair<string,string> Nganh;

};

pair<string,string> xac_dinh_Nganh(const string& MSSV)
{
	pair<string,string> Nganh={"",""};
	string check_E;
	string Ma_Nganh;
	check_E=MSSV.substr(0,1);
	Ma_Nganh=MSSV.substr(3,4);
	if(check_E!="E"&&check_E!="e")
		{
			Nganh.first=Ma_Nganh;
			if(Ma_Nganh=="DCKT")
				{
					Nganh.second="Ke toan";
				}
			else if(Ma_Nganh=="DCCN")
				{
					Nganh.second="Cong nghe thong tin";
				}
			else if(Ma_Nganh=="DCAT")
				{
					Nganh.second="An toan thong tin";
				}
			else if(Ma_Nganh=="DCVT")
				{
					Nganh.second="Vien thong";
				}
			else if(Ma_Nganh=="DCDT")
				{
					Nganh.second="Dien tu";
				}
			else Nganh.second="Khong co ma nganh tuong ung";
		}
	return Nganh;
}

string remove_blank_cutoff(string& member, size_t length)
{
	member.erase(remove(member.begin(),member.end(),' '),member.end());
	if(member.size()>length)
		member=member.substr(0,length);
	return member;
}

string cutoff(string& member, size_t length)
{
	if(member.size()>length)
		member=member.substr(0,length);
	return member;
}

int main()
{
	int num_of_Students;
	cin>>num_of_Students;
	cin.ignore();
	vector<SV> DS;
	int Querry;
	while(num_of_Students--)
	{	
		struct SV sv;
		getline(cin,sv.MS);
		getline(cin,sv.Hten);
		getline(cin,sv.Lop);
		getline(cin,sv.Email);
		sv.MS=remove_blank_cutoff(sv.MS,15);
		sv.Hten=cutoff(sv.Hten,100);
		sv.Lop=remove_blank_cutoff(sv.Lop,15);
		sv.Email=remove_blank_cutoff(sv.Email,50);
		sv.Nganh=xac_dinh_Nganh(sv.MS);
		DS.push_back(sv);
	}
	cin>>Querry;
	cin.ignore();
	while(Querry--)
	{
		string Ten_Nganh;
		getline(cin,Ten_Nganh);
		string Upper_Ten_Nganh=Ten_Nganh;
		for(char& c: Upper_Ten_Nganh)
		{
			c=toupper(c);
		}
		cout<<"DANH SACH SINH VIEN NGANH "<<Upper_Ten_Nganh<<":"<<endl;
		for(auto& i: DS)
		{
			if(i.Nganh.second==Ten_Nganh)
				cout<<i.MS<<" "<<i.Hten<<" "<<i.Lop<<" "<<i.Email<<endl;
		}
	}
	return 0;

}

