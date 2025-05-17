//BT37.cpp
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>
#include<iomanip>

using namespace std;

struct Staff
{
	string Id;
	string Name;//khong can format
	string Gender;
	string Date_of_Birth;
	int Day_of_Birth=0;
	int Month_of_Birth=0;
	int Year_of_Birth=0;
	string Address;
	string Tax_Id;
	string Date_of_Contract;
};

void input_Staff_Info(Staff& nv)
{
	getline(cin,nv.Name);
	getline(cin,nv.Gender);
	getline(cin,nv.Date_of_Birth);
	getline(cin,nv.Address);
	getline(cin,nv.Tax_Id);
	getline(cin,nv.Date_of_Contract);
}

void format_Date_of_Birth(string& Date_of_Birth,int& Day_of_Birth, int& Month_of_Birth, int& Year_of_Birth)//xu ly xong thay doi dinh dang Date
{
	//chuan hoa dd/mm/yyyy
	stringstream ss(Date_of_Birth);
	int dd, mm, yyyy;
	char deli;
	//bo qua xet nam nhuan
	ss>>dd>>deli>>mm>>deli>>yyyy;
	Day_of_Birth=dd;
	Month_of_Birth=mm;
	Year_of_Birth=yyyy;
	stringstream formated_Date;
	formated_Date<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	Date_of_Birth=formated_Date.str();
}


void format_Date_of_Contract(string& Date_of_Contract)//xu ly xong thay doi dinh dang Date
{
	//chuan hoa dd/mm/yyyy
	stringstream ss(Date_of_Contract);
	int dd, mm, yyyy;
	char deli;
	//bo qua xet nam nhuan
	ss>>dd>>deli>>mm>>deli>>yyyy;
	stringstream formated_Date;
	formated_Date<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	Date_of_Contract=formated_Date.str();
}

void format_Name(string& Name)
{
	int length_of_Name=Name.size();
	if(length_of_Name>40)
		Name=Name.substr(0,40);
}

void format_Address(string& Address)
{
	int length_of_Add=Address.size();
	if(length_of_Add>100)
		Address=Address.substr(0,100);
}

void format_Tax_Id(string& Tax_Id)
{
	stringstream formated_Tax_Id;
	formated_Tax_Id<<setw(10)<<setfill('0')<<Tax_Id;
	Tax_Id=formated_Tax_Id.str();
}

void format_Id(string& Id, int counter)//counter=0 ++
{
	stringstream formated_Id;
	formated_Id<<setw(5)<<setfill('0')<<counter;
	Id=formated_Id.str();
}

bool is_Older(const Staff& a, const Staff& b)
{
	if(a.Year_of_Birth!=b.Year_of_Birth) return a.Year_of_Birth<b.Year_of_Birth;//sap xep gia -> tre
	else
	{
		if(a.Month_of_Birth!=b.Month_of_Birth) return a.Month_of_Birth<b.Month_of_Birth;
		else
		{
			return a.Day_of_Birth<b.Day_of_Birth;
		}
	}
}

int main()
{
	int testcases; cin>>testcases;
	vector<Staff> Year_old_Staff;
	int counter=0;
	cin.ignore();
	while(testcases--)
	{
		counter++;
		Staff nv1;
		input_Staff_Info(nv1);
		format_Id(nv1.Id, counter);
		format_Name(nv1.Name);
		format_Date_of_Birth(nv1.Date_of_Birth,nv1.Day_of_Birth,nv1.Month_of_Birth,nv1.Year_of_Birth);
		format_Address(nv1.Address);
		format_Tax_Id(nv1.Tax_Id);
		format_Date_of_Contract(nv1.Date_of_Contract);
		Year_old_Staff.push_back(nv1);

	}
	sort(Year_old_Staff.begin(), Year_old_Staff.end(), is_Older);
	for(auto i: Year_old_Staff)
	{
		cout<<i.Id<<" "<<i.Name<<" "<<i.Gender<<" "<<i.Date_of_Birth<<" "<<i.Address<<" "<<i.Tax_Id<<" "<<i.Date_of_Contract<<endl;
	}

}
