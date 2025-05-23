//BT41_REv0.cpp
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<vector>
#include<cctype>
#include<cmath>

using namespace std;


string format_Date(const string& Date)
{
	stringstream ss(Date);
	int dd,mm,yyyy;
	char deli1, deli2;
	ss>>dd>>deli1>>mm>>deli2>>yyyy;
	stringstream sss;
	sss<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	return sss.str();
}

string format_Length(const string& member, size_t length)
{
	if(member.size()>length) return member.substr(0,length);
	return member;
}



class Staff
{
	public:
	enum class GenderType {Nam, Nu};
	GenderType Gender;

	int Id;
	string Name;

	string Date_of_birth;
	string Address;
	string tax_Id;
	string Date_of_contract;
	static int counter;

	Staff()
	{
		Id=counter++;
	}

	static GenderType stringToGender(const string& str)
	{
		if(str=="Nam"||str=="nam") return GenderType::Nam;
		if(str=="Nu"||str=="nu") return GenderType::Nu;
		return GenderType::Nam;
		//throw invalid_argument("Nhap Nam/ Nu");
	}

	static string genderToString(GenderType gt)
	{
		return (gt==GenderType::Nam)?"Nam":"Nu";
	}

	friend ostream& operator<<(ostream& out,const Staff& nv)
	{
		out<<setw(5)<<setfill('0')<<nv.Id<<" "<<nv.Name<<" "<<genderToString(nv.Gender)<<" "<<nv.Date_of_birth<<" "<<nv.Address<<" "<<nv.tax_Id<<" "<<nv.Date_of_contract<<endl;
		return out;
	}

	friend istream& operator>>(istream& in, Staff& nv)
	{
		string GenderStr;//bien tam cua Gender
		getline(in,nv.Name);nv.Name=format_Length(nv.Name,40);
		getline(in,GenderStr);nv.Gender=stringToGender(GenderStr);
		getline(in,nv.Date_of_birth);nv.Date_of_birth=format_Date(nv.Date_of_birth);
		getline(in,nv.Address);nv.Address=format_Length(nv.Address,100);
		getline(in,nv.tax_Id);nv.tax_Id=format_Length(nv.tax_Id,10);
		getline(in,nv.Date_of_contract);nv.Date_of_contract=format_Date(nv.Date_of_contract);
		return in;
	}

};

int Staff::counter=1;


int main()
{
	int Num_of_staff;
	cin>>Num_of_staff;
	//int index=Num_of_staff;
	vector<Staff> Staff_list;
	cin.ignore();

	while(Num_of_staff--)
	{
		Staff nv;
		cin>>nv;
		Staff_list.push_back(nv);

	}
	for(const auto& i: Staff_list)
	{
		cout<<i;
	}
}
