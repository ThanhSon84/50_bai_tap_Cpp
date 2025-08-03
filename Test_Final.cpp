//Test_Final.cpp
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
	string Maso;
	double GPA1, GPA2, GPA3;
	double TotalGPA;
	
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

void format_Maso(string& Maso)
{
	// Giữ lại chỉ ký tự chữ hoa và số, tối đa 10 ký tự
	string newMaso;
	for(char c : Maso) {
		if((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			newMaso += c;
			if(newMaso.size() == 10) break;
		}
	}
	Maso = newMaso;
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
	getline(cin,sv.Maso);

	// Đọc và kiểm tra GPA1, GPA2, GPA3
	while (true) {
		cin >> sv.GPA1 >> sv.GPA2 >> sv.GPA3;
		if (
			sv.GPA1 >= 0.0 && sv.GPA1 <= 10.0 &&
			sv.GPA2 >= 0.0 && sv.GPA2 <= 10.0 &&
			sv.GPA3 >= 0.0 && sv.GPA3 <= 10.0
		) break;
		else {
			cout << "Nhap lai GPA1, GPA2, GPA3 (0-10): ";
		}
	}
	
	// Tính tổng điểm
	sv.TotalGPA = sv.GPA1 + sv.GPA2 + sv.GPA3;
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
		format_Maso(sv1.Maso);
		Name_Students.push_back(sv1);

	}

	sort(Name_Students.begin(),Name_Students.end(),greater_Name);
	for(auto i: Name_Students)
	{
		cout<<++stt<<" "<<i.Id<<" "<<i.Name<<" "<<i.Maso<<" "<<fixed<<setprecision(1)<<i.TotalGPA<<endl;
	}
}
