#include <iostream>
using namespace std;

class A								// 基类A
{
public:
	virtual void f()				// 虚函数
	{
		cout<<"class A"<<endl;
	}
};

class B								// 基类B
{
public:
	void f()						// 非虚函数
	{
		cout<<"class B"<<endl;
	}
};

class C:public A,public B			//派生类C，从类A、B派生
{
public:
	void f()						// 重写基类函数
	{
		cout<<"class C"<<endl;
	}
};

int main()
{ 
	A a, *pa;							// 定义基类A的对象和指针
	B b, *pb;							// 定义基类B的对象和指针
	C c;								// 定义派生类C的对象
	pa =&a;								// 基类的指针指向基类对象
	cout<<"基类指针pa指向基类对象a：";
	pa->f();							// pa指向对象a，调用A类的f()
	pa=&c;								// 基类指针指向派生类类对象c
	cout<<"基类指针pa指向派生类类对象c：";
	pa->f();							
	// pa指向对象C，因为基类的f()是虚函数，随指向的对象而改变，所以调用C类的f()
	pb =&b;								// 基类的指针指向基类对象
	cout<<"基类指针pb指向基类对象b：";
	pb->f();							// pb指向对象b，调用B类的f()
	pb=&c;								//基类指针指向派生类类对象c
	cout<<"基类指针pb指向派生类类对象c：";
	pb->f();
	// pb指向对象C，因为基类的f()不是虚函数，不随指向的对象而改变，所以调用B类的f()
	system("pause");
    return 0;
}
/*
基类指针pa指向基类对象a：class A
基类指针pa指向派生类类对象c：class C
基类指针pb指向基类对象b：class B
基类指针pb指向派生类类对象c：class B
*/