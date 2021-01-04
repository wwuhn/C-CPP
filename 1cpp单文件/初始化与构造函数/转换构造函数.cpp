#include <iostream>
using namespace std;

class Complex;
Complex operator+(Complex &c1,Complex &c2);

class Complex
{
public:
	Complex(){real=0;vir=0;}                    //构造函数1

	Complex(double r){real=r;vir=0;}            //构造函数2/转换构造函数

	Complex(double r,double i):real(r),vir(i){} //构造函数3

	friend Complex operator+(Complex &c1,Complex &c2);  //重载"+"运算符

	operator double(){return real;}                     //类型转换函数

	void show()
	{
		cout<<real<<"+"<<vir<<"i"<<endl;
	}
    
private:
	double real;
	double vir;
};

//还需在类外定义运算符重载函数operator +如下
Complex operator+(Complex &c1,Complex &c2)
{return Complex(c1.real+c2.real,c1.vir+c2.vir);}


void main()
{
	
	Complex a(3,5);
	Complex b=5.0;//或Complex t(5.0);或Complex t=Complex(5.0);或Complex t=(Complex)5.0;
	Complex c=a + 4.8;

	c.show();
    system("pause");
}
//7.8+0i
