//BT25.cpp
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> input_Matrix(int& rows, int& cols)
{
	vector<vector<int>> v(rows,vector<int>(cols));
	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<cols;col++)
		{
			cin>>v[row][col];
		}
	}
	return v;
}

void rotate_Matrix(vector<vector<int>>& v)
{
	int rows=v.size();
	int cols=v[0].size();
	int layers=min(rows,cols)/2;
	for(int layer=0;layer<layers;layer++)
	{
		int top_row=layer, left_col=layer;
		int bottom_row=rows-1-layer;//-1 thi dieu kien for them=
		int right_col=cols-1-layer;
		//dieu kien dung ham for
		if(top_row>=bottom_row||left_col>=right_col) return;
		//luu bien chuan bi cho [0][0]
		int prev=v[top_row+1][left_col];//ptu se thay vao [0][0]
		//cout<<"prev="<<prev<<" ";
		//xoay hang tren cung
		for(int col=left_col;col<=right_col;col++)
		{
			int tmp=v[top_row][col];
			v[top_row][col]=prev;
			prev=tmp;
		}

		//xoay cot ben phai (bo 1 phan tu dau)
		for(int row=top_row+1;row<=bottom_row;row++)
		{
			int tmp=v[row][right_col];
			v[row][right_col]=prev;
			prev=tmp;
		}

		//xoay hang duoi (chieu giam, bo 1 phan tu)
		for(int col=right_col-1;col>=left_col;col--)
		{
			int tmp=v[bottom_row][col];
			v[bottom_row][col]=prev;
			prev=tmp;
		}

		//xoay cot trai (chieu giam, bo 1 ptu)
		for(int row=bottom_row-1;row>=top_row;row--)
		{
			int tmp=v[row][left_col];
			v[row][left_col]=prev;
			prev=tmp;
		}

	}


}

void print_Matrix(vector<vector<int>>& v)
{
	int rows=v.size();
	int cols=v[0].size();
	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<cols;col++)
		{
			cout<<v[row][col]<<" ";
		}
	}
}

int main()
{
	int test; cin>>test;
	while (test--)
	{
		int rows, cols; cin>>rows>>cols;
		vector<vector<int>> v=input_Matrix(rows,cols);
		rotate_Matrix(v);
		print_Matrix(v);
		cout<<endl;
	}
}
