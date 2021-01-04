#include<iostream.h>

class CShape
{
public:
	virtual double Area()
	{cout<<"Area calculating interface."<<endl;return 0;}
};

class CTriangle:public CShape
{
	double base,high;
public:
	CTriangle(double b=0,double h=0):base(b),high(h){}
	double Area()
	{return base*high/2.0;}
};

class CCircle:public CShape
{
	double r;
	const double PI;
public:
	CCircle(double rr=0,double pi=3.14159):r(rr),PI(pi){}
	double Area()
	{return PI*r*r;}
};

void main() 
{ 
	CShape* sp;
	CTriangle tri(11,11);
	CCircle cir(11);
	sp = &tri;
	cout<<sp->Area()<<endl;
	sp = &cir;
	cout<<sp->Area()<<endl;
	cin.ignore();
}