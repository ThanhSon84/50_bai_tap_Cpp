//BT16_rev1.cpp
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int m, s;//m chu so, s tong gia tri
	cin>>m>>s;
	//xu ly ngoai le
	if(s==0)
	{
		if(m==1)
		{
			cout<<0<<" "<<0;
			return 0;
		}
		else
		{
			cout<<-1<<" "<<-1;
			return 0;
		}
	}

	if(s<10&&m==1)
	{
		cout<<s<<" "<<s;
		return 0;
	}

	if(s>m*9)
	{
		cout<<-1<<" "<<-1;
		return 0;
	}
	else
	{
		//TIM MIN-----------------------------//
		//pham vi bien
		//s<=m*9
		//min max khong phai dang reverse
	
		int s_copy_min_val=s;//gia tri se thay doi
		int m_copy_min_val=m;//gia tri se thay doi
		vector<int> min_val(m,0);//tao vector int co m pt voi init_val=0
		//2 truong hop
		//gia tri dau tien la 1
		//hoac phan con lai
		//tao bien kiem tra phan con lai min_val[0]
		m_copy_min_val--;//2->1
		while(s_copy_min_val>9)
		{
			min_val[m_copy_min_val]=9;//a[1]=9
			s_copy_min_val-=9;//con lai 15-9=6
			m_copy_min_val--;//1->0
		}
		//sau vong while s_copy_min_val <9
		//kiem tra m_copy_min_val con lai bao nhieu ptu
		if(m_copy_min_val!=0)
		{
			//phan tu hien hanh= s_copy_min_val-1
			//ptu [0]=1 de dam bao m chu so
			--s_copy_min_val;
			min_val[m_copy_min_val]=s_copy_min_val;
			min_val[0]=1;
		}
		else
		{
			min_val[m_copy_min_val]=s_copy_min_val;//a[0]=6
		}

		//TEST-------------------------------------//
		for(int i=0;i<m;i++)
		{
			cout<<min_val[i];
		}

		cout<<" ";
		

		//TIM MAX----------------------------------//

		int s_copy_max_val=s;//gia tri se thay doi
		int m_copy_max_val=0;//gia tri se thay doi
		vector<int> max_val(m,0);//tao vector int co m pt voi init_val=0
		//gia tri dau tien la 9
		while(s_copy_max_val>=9)//
		{
			max_val[m_copy_max_val]=9;
			s_copy_max_val-=9;
			m_copy_max_val++;//chi so phan tu ke tiep
		}
		//sau vong while s_copy_max_val <9
		//gia tri s_copy_max_val con lai
		max_val[m_copy_max_val]=s_copy_max_val;
		//-----------------------------------//IN KQ
		/*
		for(int i=0;i<m-1;i++)
		{
			cout<<min_val[i];
		}

		cout<<" ";
		*/

		for(int i=0;i<m;i++)
		{
			cout<<max_val[i];
		}


	}//ket thuc else

	return 0;//ket thuc main

}
