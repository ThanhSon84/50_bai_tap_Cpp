//BT36.cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<string>
#include<iomanip>
#include<sstream>
#include<cmath>

using namespace std;

struct Student
{
	string Id="B20DCCN002";
	string Name;
	string Class;
	string Date_of_Birth;
	double GPA;
};

void input_Info(Student& sv)
{
	getline(cin,sv.Name);
	getline(cin,sv.Class);
	getline(cin,sv.Date_of_Birth);
	cin>>sv.GPA;
	cin.ignore();
}

void format_Id(string& Id, int counter)
{
	stringstream formated_Id;
	formated_Id<<setw(3)<<setfill('0')<<counter;
	Id+=formated_Id.str();
	//return Id;
}

void format_GPA(double& GPA)
{
	GPA=round(GPA*100)/100.0;
	//return GPA;
}

void format_Name(string& Name)
{
	string formated_Name;
	string word;
	stringstream ss(Name);
	while(ss>>word)
	{
		if(!word.empty())
		{		
		word[0]=toupper(word[0]);
		for(size_t i=1;i<word.size();i++)
			{
				word[i]=tolower(word[i]);
			}
		formated_Name+=word+" ";
		}
	}

	if(!formated_Name.empty())
	{
		formated_Name.pop_back();
	}

	int length_of_Name=formated_Name.size();
	if(length_of_Name>30)
	{
		Name=formated_Name.substr(0,30);
	}
	else Name=formated_Name;

	//return Name;
}

bool is_Leap_Year(const int& Year)
{
	return ((Year%4==0&&Year%100!=0)||(Year%400==0));
}

bool is_format_Date(const string& Date)
{
	int dd,mm,yyyy;
	char deli;

	stringstream ss(Date);
	ss>>dd>>deli>>mm>>deli>>yyyy;

	if(dd<1) return false;
	if(mm<1||mm>12) return false;
	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
	{
		if(dd<=31) return true;
		else
			return false;
	}
	else if (mm==4||mm==6||mm==9||mm==11)
	{
		if(dd<=30) return true;
		else
			return false;
	}
	else
	{
		if(is_Leap_Year(yyyy))
			if(dd<=29) 
				return true;
			else
				return false;
		else
			if(dd<=28)
				return true;
			else
				return false;
	}
}

void format_Date(string& Date)
{
	stringstream formated_Date;
	if(!is_format_Date(Date))
		Date="N/A";
	else
	{
		int dd,mm,yyyy;
		char deli;

		stringstream ss(Date);
		ss>>dd>>deli>>mm>>deli>>yyyy;
		formated_Date<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
		Date=formated_Date.str();
	}	

//return Date;

}

int main()
{
	int Number_of_Students;
	cin>>Number_of_Students;
	vector<Student> GPAs_Student;
	int stt=1;
	cin.ignore();
	while(Number_of_Students--)
	{
		Student sv1;
		input_Info(sv1);
		format_Id(sv1.Id,stt);
		format_Name(sv1.Name);
		format_Date(sv1.Date_of_Birth);
		format_GPA(sv1.GPA);
		GPAs_Student.push_back(sv1);
		stt++;
	}
	sort(GPAs_Student.begin(),GPAs_Student.end(),[](const Student& a, const Student& b)
		{
		return a.GPA>b.GPA;
		}
	);

	for(auto i: GPAs_Student)
	{
		cout<<i.Id<<" "<<i.Name<<" "<<i.Class<<" "<<i.Date_of_Birth<<" "<<fixed<<setprecision(2)<<i.GPA<<endl;
	}
}
