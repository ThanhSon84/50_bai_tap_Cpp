//BT34.cpp
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Student
{
	string Id="B20DCCN";
	string Full_name;
	string student_class;
	string Date_of_birth;
	double GPA;
	//void input_info_student();


};

void input_info_student(struct Student& sv)
{
	cin.ignore();
	getline(cin,sv.Full_name);
	getline(cin,sv.student_class);
	getline(cin,sv.Date_of_birth);
	//chuan hoa ngay thang
	//nam nhuan chia cho 
	cin>>sv.GPA;
}

int main()
{
	int number_student;
	cin>>number_student;
	int stt=0;
	while(number_student--)
	{
		struct Student sv1;
		stt++;
		input_info_student(sv1);
		cout<<sv1.Id<<setw(3)<<setfill('0')<<stt<<" "<<sv1.Full_name<<" "<<sv1.student_class<<" "<<sv1.Date_of_birth<<" "<<fixed<<setprecision(2)<<sv1.GPA<<endl;
	}
}
