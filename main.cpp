#include <iostream>
#include"Dynamic_Array.h"
#include"stdafx.h"
using namespace std;

int main()
{
    myArray<int> obj1(6,1);
	obj1.array_output();
	int length = obj1.getLenth();
	cout << "数组长度" << length << endl;
	for (int i = 0; i < length; ++i) {
		obj1[i] = i;
	}
	obj1.push_back(6);
	obj1.push_back(7);
	obj1.push_back(8);
	obj1.push_back(9);
	obj1.push_back(10);
	obj1.push_back(11);
	obj1.push_back(12);
	cout<< obj1[7]<<endl;
	obj1.array_output();
	int a = 1;
	obj1.judge_value(a);
	
	system("pause");
}
