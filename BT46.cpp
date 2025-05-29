//BT46.cpp
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

struct DN
{
	string MS;
	string Ten;
	int SL;

};

string cutoff_length(string& member, size_t length)
{
	if(member.size()> length) member=member.substr(0, length);
	return member;
}

bool standard_SL(struct DN& a, struct DN& b)
{
	if(a.SL!=b.SL) return a.SL>b.SL;
	else
		return a.MS<b.MS;
}

int main()
{
	int so_cty;
	cin>>so_cty;
	vector<DN> DS;
	cin.ignore();
	while(so_cty--)
	{
		struct DN dn;
		getline(cin,dn.MS);
		getline(cin,dn.Ten);
		cin>>dn.SL;
		cin.ignore();//phan nay quan trong
		dn.MS=cutoff_length(dn.MS,10);
		dn.Ten=cutoff_length(dn.Ten,150);
		DS.push_back(dn);
	}
	sort(DS.begin(),DS.end(),standard_SL);
	for(auto& it: DS)
		cout<<it.MS<<" "<<it.Ten<<" "<<it.SL<<endl;

}
