//BT40.cpp
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct Person
{
	string Name;
	string Date;
	int Day;
	int Month;
	int Year;
};

void format_Name(string& Name)
{
	Name.erase(remove(Name.begin(),Name.end(),' '),Name.end());
	if(Name.size()>15) Name=Name.substr(0,15);
}

void format_Date(string& Date, int& Day, int& Month, int& Year)
{
	stringstream ss(Date);
	int dd, mm, yyyy;
	char deli;
	ss>>dd>>deli>>mm>>deli>>yyyy;

	Day=dd;
	Month=mm;
	Year=yyyy;

	stringstream sss;
	sss<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
	Date=sss.str();

}

void input_Info(Person& ns)
{
	cin>>ns.Name>>ns.Date;
}

bool Younger(const Person& a, const Person& b)
{
	if(a.Year!=b.Year)
		return a.Year>b.Year;
	else if (a.Month!=b.Month)
		return a.Month>b.Month;
	else
		return a.Day>b.Day;
}

int main()
{
	int number_of_person;
	int copy_num_of_person;
	cin>>number_of_person;
	copy_num_of_person=number_of_person-1;
	vector<Person> year_old_People;
	while(number_of_person--)
	{
		struct Person ns1;
		input_Info(ns1);
		format_Name(ns1.Name);
		format_Date(ns1.Date,ns1.Day,ns1.Month,ns1.Year);
		year_old_People.push_back(ns1);
	}

	sort(year_old_People.begin(),year_old_People.end(),Younger);

		cout<<year_old_People[0].Name<<endl<<year_old_People[copy_num_of_person].Name<<endl;

}
