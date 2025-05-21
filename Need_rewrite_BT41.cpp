//BT41.cpp
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
#include<cctype>

using namespace std;

string format_Id(int& counter)
{
	stringstream ss;
	ss<<setw(5)<<setfill('0')<<counter++;
	return ss.str();
}

string Length_of_member(const string& member, size_t length)//Dia chi, ho ten,  ma so thue
{
	if(member.size()>length)
		return member.substr(0,length);
	return member;
}

string format_Date(const string& Date)//Date of birth, contract
{
	stringstream time(Date);
	int dd, mm, yyyy;
	char deli;
	time>>dd>>deli>>mm>>deli>>yyyy;
	stringstream format_time;
	format_time<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	
	return format_time.str();

}

class Staff
{
public:
	string Id;
	string Name;
	string Gender;
	string Address;
	string Tax_Id;
	string Date_of_birth;
	string Date_of_Contract;

	friend ostream& operator<<(ostream& out, const Staff& nv)
	{
		out<<nv.Id<<" "<<Length_of_member(nv.Name,40)<<" "<<nv.Gender<<" "<<format_Date(nv.Date_of_birth)<<" "<<Length_of_member(nv.Address,100)<<" "<<Length_of_member(nv.Tax_Id, 10)<<" "<<format_Date(nv.Date_of_Contract)<<endl;
		return out;
	}

	friend istream& operator>>(istream& in,Staff& nv)
	{
		getline(in>>ws,nv.Name);
		getline(in,nv.Gender);
		getline(in,nv.Date_of_birth);
		getline(in,nv.Address);
		getline(in,nv.Tax_Id);
		getline(in, nv.Date_of_Contract);
		
		return in;
	}
};


int main() 
{
	int N; cin>>N;
	//N- so nv
	vector<Staff> person_in_company;
	int counter=1;
	cin.ignore();
	while(N--)
	{
		Staff nv1;
		cin>>nv1;
		nv1.Id=format_Id(counter);
		person_in_company.push_back(nv1);

	}
	for(const auto& i: person_in_company)
	{
		cout<<i;
	}
}
