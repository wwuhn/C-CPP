#include <iostream>

class complex
{
private:
	double real, imag;
public:
	complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	friend void print(const complex& c);
	friend complex operator+(const complex & p,const complex & p2);
};

complex operator+(const complex & p1,const complex & p2)
{
    complex temp;
    temp.real = p1.real + p2.real;
	temp.imag = p1.imag + p2.imag;
    return temp;
}

void print(const complex& c)
{
	std::cout<<"("<<c.real<<","<<c.imag<<")"<<std::endl;
}

int main()
{
	complex a(3,4), b(5,6), c;
	c = a+b;
	//c=operator+(a,b);
	print(c);//(4,6)
	std::cin.get();
	return 0;
}