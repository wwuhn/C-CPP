#include <iostream>
//using namespace std;//frined:INTERNAL COMPILER ERROR

class complex
{
private:
	double real, imag;
public:
	complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
	//complex(const complex& c):real(c.real),imag(c.imag){}  // 复制构造函数
	friend complex add(const complex &c1, const complex &c2);
	friend complex operator+(const complex& c1, const complex& c2);
	friend complex& assign(complex &c1, const complex &c2);
	friend void print(const complex& c);

};

complex add(const complex &c1, const complex &c2)
{
	complex temp(c1.real + c2.real, c1.imag + c2.imag);
	return temp;
}

complex operator+(const complex& c1, const complex& c2)
{
	complex temp(c1.real + c2.real, c1.imag + c2.imag);
	return temp;
}

complex& assign(complex &c1, const complex &c2)
{
	c1.real = c2.real; 
	c1.imag = c2.imag;
	return c1;
}

void print(const complex& c)
{
	std::cout<<"("<<c.real<<","<<c.imag<<")"<<std::endl;
}

int main()
{
	complex a(1,2), b(3,4), c, d;
	c = add(a,b);
	c = c+a;
	print(c);
	d = a;
	print(d);
	std::cin.get();
	return 0;
}