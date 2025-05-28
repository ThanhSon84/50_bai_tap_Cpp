//BT43.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct SV
{
	string MSV;
	string Hten;
	string Lop;
	string Email;

};

bool standard_MS(struct SV& a, struct SV& b)
{
	return a.MSV<b.MSV;
}

string remove_space_cutoff(string& member, size_t length)
{
	member.erase(remove(member.begin(),member.end(),' '),member.end());
	if (member.size()>length)
		member=member.substr(0,length);
	return member;
}

string cutoff(string& member,size_t length)
{
	if (member.size()>length)
		member=member.substr(0,length);
	return member;
}

int main()
{
	vector<SV> DS;
	struct SV sv1;
	while(getline(cin,sv1.MSV))
	{
		getline(cin,sv1.Hten);
		getline(cin,sv1.Lop);
		getline(cin,sv1.Email);
		sv1.MSV=remove_space_cutoff(sv1.MSV,15);
		sv1.Hten=cutoff(sv1.Hten,100);
		sv1.Lop=remove_space_cutoff(sv1.Lop,15);
		sv1.Email=remove_space_cutoff(sv1.Email,15);
		DS.push_back(sv1);
	}

	sort(DS.begin(),DS.end(),standard_MS);
	for(auto& i : DS)
	{
		cout<<i.MSV<<" "<<i.Hten<<" "<<i.Lop<<" "<<i.Email<<endl;
	}
}
