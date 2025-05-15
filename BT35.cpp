//BTnn.cpp
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>

using namespace std;

struct Student
{
	string Id="AAAAA";
	string Full_name;
	string Class;
	string Date_of_Birth;;
};

void input_info(struct Student& sv)
{
	//cin.ignore();
	getline(cin,sv.Full_name);
	getline(cin,sv.Class);
	getline(cin,sv.Date_of_Birth);
}

bool is_Leap_year(int Year)
{
	return ((Year%4==0&&Year%100!=0)||(Year%400==0));
}

bool is_right_format_Date(const string& Date)
{
	//copy Date vao chuoi de tach
	stringstream ss(Date);
	int dd,mm,yyyy;
	char delimiter;//cach dd-deli-mm-deli-yyyy
	//tach
	ss>>dd>>delimiter>>mm>>delimiter>>yyyy;
	//kiem tra tinh hop le
	if(dd<1) return false;//ngay khong hop le
	if(mm<1||mm>12) return false;//thang ko hop le
	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
	{
		if(dd<=31) return true;
		else return false;
	}
	else if (mm==4||mm==6||mm==9||mm==11)
	{
		if(dd<=30) return  true;
		else return false;
	}
	else
	{
		if(is_Leap_year(yyyy))
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

//tra ve ngay thang da format
string right_format_Date(const string& Date)
{
	stringstream ss(Date);
	int dd, mm, yyyy;
	char deli;
	//tach chuoi
	ss>>dd>>deli>>mm>>deli>>yyyy;
	//tao chuoi co ngan deli
	//stringsgtrem
	stringstream format_Date;
	format_Date<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;

	return format_Date.str();

}

int main()
{
	int testcases;
	cin>>testcases;
	int stt=0;
	cin.ignore();
	while(testcases--)
	{
		Student sv1;
		stt++;
		//cin.ignore();
		input_info(sv1);
		string DoB=right_format_Date(sv1.Date_of_Birth);
		if(!is_right_format_Date(DoB)) DoB="N/A";
		cout<<sv1.Id<<stt<<" "<<sv1.Full_name<<" "<<sv1.Class<<" "<<DoB<<endl;

	}
}
