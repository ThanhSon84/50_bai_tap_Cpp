//BT21.cpp
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;


struct Staff
{
	string Id="00001";
	string Full_Name;
	string Gender;
	string Date_of_Birth;
	string Adress;
	string Tax_Id;
	string Date_of_Contract;

};

string format_Date(const string& Date)
{
	stringstream ss(Date);
	int dd, mm, yyyy;
	char delimiter;

	ss>>dd>>delimiter>>mm>>delimiter>>yyyy;

	stringstream formated_Date;
	formated_Date<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	return formated_Date.str();
}

void input_info_staff(Staff& nv)
{
	string pre_process_Tax_Id;
	getline(cin,nv.Full_Name);
	//Xu ly dinh dang ten
	if(nv.Full_Name.length()>40)
	{
		nv.Full_Name=nv.Full_Name.substr(0,40);
	}
	getline(cin,nv.Gender);
	getline(cin,nv.Date_of_Birth);
	nv.Date_of_Birth=format_Date(nv.Date_of_Birth);
	getline(cin,nv.Adress);
	getline(cin,nv.Tax_Id);
	//Xu ly dinh dang
	if(nv.Tax_Id.length()<10)//do length() co kem ky tu \0
	{
		nv.Tax_Id=string(10-nv.Tax_Id.length(),'0')+nv.Tax_Id;
	}
	getline(cin,nv.Date_of_Contract);
	nv.Date_of_Contract=format_Date(nv.Date_of_Contract);
}

void print_info(Staff& nv)
{
	cout<<nv.Id<<" "<<nv.Full_Name<<" "<<nv.Gender<<" "<<nv.Date_of_Birth<<" "<<nv.Adress<<" "<<nv.Tax_Id<<" "<<nv.Date_of_Contract;
}

int main()
{
	Staff nv;
	input_info_staff(nv);
	print_info(nv);
	//cout<<nv.Tax_Id.length();

	return 0;
}
