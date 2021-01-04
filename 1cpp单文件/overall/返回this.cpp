#include <iostream>
using namespace std;

class Complex 
{ 
public: 
	double real, imag; 

	void Print() 
	{ cout << real << "," << imag ; } 

	Complex(double r,double i):real(r),imag(i) { } 

	Complex AddOne() { 
		this->real ++; //等价于 real ++; 
		this->Print(); //等价于 Print 
		return * this; } 
}; 

int main() 
{ 
	Complex c1(1,1),c2(0,0); 
	c2 = c1.AddOne(); 
	return 0; 
} //输出 2,1
