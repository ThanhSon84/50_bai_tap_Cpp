//BT24.cpp
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	
	//thiet lap file goc (read) -> dich (write)
	ifstream fread("PTIT.in", ios::binary);
	ofstream fwrite("PTIT.out",ios::binary);

	//chuyen file goc vao bo nho-> file dich doc bo nho dem
	fwrite<<fread.rdbuf();


	return 0;
}
