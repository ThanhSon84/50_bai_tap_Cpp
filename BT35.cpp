//BT34.cpp
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#include<cctype>

using namespace std;

struct Student
{
	string Id="B20DCCN";
	string Full_name;
	string Class;
	string Date_of_Birth;
	double GPA;
};

void input_info(struct Student& sv)
{
	//cin.ignore();
	getline(cin,sv.Full_name);
	getline(cin,sv.Class);
	getline(cin,sv.Date_of_Birth);
	cin>>sv.GPA;
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

string format_Name(string& Name)
{
	int length_of_Name=Name.size();
	if(length_of_Name>30) Name=Name.substr(0,30);
	stringstream ss(Name);
	string formated_Name;
	string word;
	while(ss>>word)
	{
		word[0]=toupper(word[0]);
		for(size_t i=1;i<word.size();i++)//size_t tuong tu int nhung ko co dau
			word[i]=tolower(word[i]);
		formated_Name+=word+" ";
	}
	//xoa dau cach cuoi do ham tren chay xong thua 1 khoang " "
	if(!formated_Name.empty())
	{
		formated_Name.pop_back();
	}

	return formated_Name;

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
		string Student_Name=format_Name(sv1.Full_name);
		cout<<sv1.Id<<stt<<" "<<Student_Name<<" "<<sv1.Class<<" "<<DoB<<" "<<fixed<<setprecision(2)<<sv1.GPA<<endl;

	}
}
