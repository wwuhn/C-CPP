#include <iostream>
using namespace std;

class Complex;
Complex operator+(Complex &c1,Complex &c2);

class Complex
{
public:
	Complex(){real=0;vir=0;}                    //���캯��1

	Complex(double r){real=r;vir=0;}            //���캯��2/ת�����캯��

	Complex(double r,double i):real(r),vir(i){} //���캯��3

	friend Complex operator+(Complex &c1,Complex &c2);  //����"+"�����

	operator double(){return real;}                     //����ת������

	void show()
	{
		cout<<real<<"+"<<vir<<"i"<<endl;
	}
    
private:
	double real;
	double vir;
};

//���������ⶨ����������غ���operator +����
Complex operator+(Complex &c1,Complex &c2)
{return Complex(c1.real+c2.real,c1.vir+c2.vir);}


void main()
{
	
	Complex a(3,5);
	Complex b=5.0;//��Complex t(5.0);��Complex t=Complex(5.0);��Complex t=(Complex)5.0;
	Complex c=a + 4.8;

	c.show();
    system("pause");
}
//7.8+0i
