#include <iostream>
using namespace std;

class A
{
	const int SIZE;
public:
	A(int size); //构造函数
	void getv(){cout<<SIZE<<endl;}
};
A::A(int size):SIZE(size){} //构造函数的初始化表


void main()
{
	
	A a(100); //对象a的SIZE的值为100
	A b(200); //对象b的SIZE的值为200
	
	b.getv();	
    system("pause");
}
