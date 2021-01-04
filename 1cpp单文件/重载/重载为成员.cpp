#include <iostream>

class complex
{
private:
	double real, imag;
public:
	complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	friend void print(const complex& c);
	complex operator+(const complex & p2);
};

complex complex::operator+(const complex & p2)
{
    complex temp(*this);
    temp.real = temp.real + p2.real;
	temp.imag = temp.imag + p2.imag;
    return temp;
}

void print(const complex& c)
{
	std::cout<<"("<<c.real<<","<<c.imag<<")"<<std::endl;
}

int main()
{
	complex a(1,2), b(3,4), c;
	c = a+b;
	//c=a.operator+(b);
	print(c);//(4,6)
	std::cin.get();
	return 0;
}