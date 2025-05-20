//BT39.cpp
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<cctype>

using namespace std;

struct Student
{
	string Id;
	string Name;
	string Class;
	double GPA1, GPA2, GPA3;
	
};

void format_Id(string& Id)
{
	Id.erase(remove(Id.begin(),Id.end(),' '),Id.end());
	if(Id.size()>15)
		Id=Id.substr(0,15);

}

void format_Name(string& Name)
{
	if(Name.size()>50)
		Name=Name.substr(0,50);

}

void format_Class(string& Class)
{
	Class.erase(remove(Class.begin(),Class.end(),' '),Class.end());
	if(Class.size()>15)
		Class=Class.substr(0,15);
}

 bool greater_Name(const Student& a, const Student& b)
 {
 	return a.Name<b.Name;
 }

void input_Info(Student& sv)
{
	cin.ignore();
	getline(cin,sv.Id);
	getline(cin,sv.Name);
	getline(cin,sv.Class);

	cin>>sv.GPA1>>sv.GPA2>>sv.GPA3;
	
}


int main()
{
	int number_of_Students;
	cin>>number_of_Students;
	int stt=0;
	vector<Student> Name_Students;
	while(number_of_Students--)
	{
		struct Student sv1;
		input_Info(sv1);
		format_Id(sv1.Id);
		format_Name(sv1.Name);
		format_Class(sv1.Class);
		Name_Students.push_back(sv1);

	}

	sort(Name_Students.begin(),Name_Students.end(),greater_Name);
	for(auto i: Name_Students)
	{
		cout<<++stt<<" "<<i.Id<<" "<<i.Name<<" "<<i.Class<<" "<<fixed<<setprecision(1)<<i.GPA1<<" "<<fixed<<setprecision(1)<<i.GPA2<<" "<<fixed<<setprecision(1)<<i.GPA3<<endl;
	}
}
