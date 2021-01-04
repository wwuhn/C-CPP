#include <iostream>
using namespace std;

int adder(int a, int b)
{
	return a+b;
}

double adder(double a, double b)
{
	return a+b;
}

void main()
{
	cout<<adder(3,4)<<endl;
	cout<<adder(3.3,4.4)<<endl;
	
    system("pause");
}
/*
7
7.7
*/