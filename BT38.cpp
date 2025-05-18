//BT38.cpp
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<sstream>
#include<cmath>

using namespace std;

struct Student
{
	//string No;
	string Id;
	string Name;
	string Class;
	double GPA1, GPA2, GPA3;

};

void format_GPA(double& GPA1, double& GPA2, double& GPA3)
{
	GPA1=round(GPA1*10)/10.0;
	GPA2=round(GPA2*10)/10.0;
	GPA3=round(GPA3*10)/10.0;
}

void format_Id(string& Id)
{
	Id.erase(remove(Id.begin(),Id.end(),' '),Id.end());
	if(Id.size()>15) Id=Id.substr(0,15);
}

void format_Name(string& Name)
{
	if(Name.size()>50) Name=Name.substr(0,50);
}

void format_CLass(string& Class)
{
	Class.erase(remove(Class.begin(),Class.end(),' '),Class.end());
	if(Class.size()>15) Class=Class.substr(0,15);
}

bool Student_Id(const Student& a, const Student& b)
{
	return a.Id<b.Id;
}

void input_Info_Student(Student& sv)
{
	cin.ignore();
	getline(cin,sv.Id);
	getline(cin,sv.Name);
	getline(cin,sv.Class);
	cin>>sv.GPA1;
	cin>>sv.GPA2;
	cin>>sv.GPA3;
}

int main()
{
	int Number_of_Students; cin>>Number_of_Students;
	vector<Student> Students_Id;
	while (Number_of_Students--)
	{
		Student sv1;
		input_Info_Student(sv1);
		format_Id(sv1.Id);
		format_Name(sv1.Name);
		format_CLass(sv1.Class);
		format_GPA(sv1.GPA1, sv1.GPA2, sv1.GPA3);
		Students_Id.push_back(sv1);
	}
	sort(Students_Id.begin(),Students_Id.end(),Student_Id);
	int stt=0;

	for(auto i: Students_Id)
	{
		cout<<++stt<<" "<<i.Id<<" "<<i.Name<<" "<<i.Class<<" "<<fixed<<setprecision(1)<<i.GPA1<<" "<<fixed<<setprecision(1)<<i.GPA2<<" "<<fixed<<setprecision(1)<<i.GPA3<<endl;
	}

}
