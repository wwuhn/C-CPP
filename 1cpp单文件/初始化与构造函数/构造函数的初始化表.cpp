#include <iostream>
using namespace std;

class A
{
	const int SIZE;
public:
	A(int size); //���캯��
	void getv(){cout<<SIZE<<endl;}
};
A::A(int size):SIZE(size){} //���캯���ĳ�ʼ����


void main()
{
	
	A a(100); //����a��SIZE��ֵΪ100
	A b(200); //����b��SIZE��ֵΪ200
	
	b.getv();	
    system("pause");
}
