 ///
 /// @file    findNumInMatrix.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;


bool findNum(int * matrix, int rows, int columns, int number)
{
	bool found = false;
	if(matrix != NULL && rows >0 && columns > 0)
	{
		int row = 0;//第一行开始
		int column = columns - 1;//最后一列开始
		while(row < rows && column >= 0)
		{
			if(matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}else if(matrix[row*columns + column] > number)
				--column;
			else ++row;
		}
	}
	return found;
}

int main()
{
	int a[][4] = {{1,2,8,9},{2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
	bool s = findNum((int *)a, 4, 4, 7);
	if(s == true) 
		cout << "Found!" << endl;
	else 
		cout << "No Found!" <<endl;
	return 0;
}
