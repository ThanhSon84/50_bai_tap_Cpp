//BT45.cpp
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<sstream>

using namespace std;


struct GV
{
	string MS;
	string Hten;
	string Bmon;

};

string lower_string(const string& a)
{
	string res;
	res=a;
	for(char& c: res)
	{
		c=tolower(c);
	}
	return res;
}

bool is_match(const string& source, const string& find)
{
	string a, b;
	a=lower_string(source);
	b=lower_string(find);
	int res;
	res=a.find(b);
	return res!=-1?1:0;

}

string cutoff_length(string& member, size_t length)
{
	if(member.size()>length) member=member.substr(0,length);
	return member;
}

string format_MS(int& stt)
{
	stt++;
	stringstream res;
	res<<setw(2)<<setfill('0')<<stt;
	return ("GV"+res.str());
}

string format_Bmon(string& Bmon)
{
	stringstream mon(Bmon);
	string format_bo_mon;
	string ky_tu_dau;
	while(mon>>ky_tu_dau)
	{
		ky_tu_dau[0]=toupper(ky_tu_dau[0]);
		format_bo_mon+=ky_tu_dau[0];
	}
	return format_bo_mon;
}

int main()
{
	int Num_GV;
	cin>>Num_GV;
	cin.ignore();
	int STT=0;
	vector<GV> DS;
	while(Num_GV--)
	{
		struct GV gv;
		getline(cin,gv.Hten);
		getline(cin,gv.Bmon);
		gv.MS=format_MS(STT);
		gv.Hten=cutoff_length(gv.Hten,50);
		gv.Bmon=format_Bmon(gv.Bmon);
		DS.push_back(gv);
	}

	int Query;
	cin>>Query;
	cin.ignore();
	while(Query--)
	{
		string Q;
		getline(cin,Q);
		//cin.ignore();
		cout<<"DANH SACH GIANG VIEN THEO TU KHOA "<<Q<<":"<<endl;
		//cin.ignore();
		for(auto& i: DS)
		{
			if(is_match(i.Hten,Q)) cout<<i.MS<<" "<<i.Hten<<" "<<i.Bmon<<endl;
		}

	}

}
