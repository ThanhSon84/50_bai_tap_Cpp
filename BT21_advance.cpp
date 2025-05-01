//BT21_advance .cpp
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

bool check_Leap_Year(int Year)
{
	return((Year%4==0&&Year%100!=0)||Year%400==0);
}

bool check_format_Date(const string& Date)
{
	stringstream ss(Date);
	int dd,mm,yyyy;
	char delimiter;

	//tach dd-mm-yyyy
	ss>>dd>>delimiter>>mm>>delimiter>>yyyy;
	if(dd<1) return false;
	if(mm<1||mm>12) return false;
	//so ngay chuan trong thang
	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
	{
		if(dd<=31) return true;
		else return false;
	}
	else if(mm==4||mm==6||mm==9||mm==11)
	{
		if(dd<=30) return true;
		else return false;
	}
	else //mm==2
	{
		if(check_Leap_Year(yyyy))
		{
			if(dd<=29) return true;
			else return false;
		}
		else
		{
			if(dd<=28) return true;
			else return false;
		}
	}
}

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
	if(check_format_Date(nv.Date_of_Birth))
	{
		nv.Date_of_Birth=format_Date(nv.Date_of_Birth);
	}
	else
	{
		nv.Date_of_Birth="Wrong_format_Date_of_Birth!";
	}
	getline(cin,nv.Adress);
	getline(cin,nv.Tax_Id);
	//Xu ly dinh dang
	if(nv.Tax_Id.length()<10)//do length() co kem ky tu \0
	{
		nv.Tax_Id=string(10-nv.Tax_Id.length(),'0')+nv.Tax_Id;
	}
	getline(cin,nv.Date_of_Contract);
	if(check_format_Date(nv.Date_of_Contract))
	{
		nv.Date_of_Contract=format_Date(nv.Date_of_Contract);
	}
	else
	{
		nv.Date_of_Contract="Wrong_format_Date_of_Contract!";
	}
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
