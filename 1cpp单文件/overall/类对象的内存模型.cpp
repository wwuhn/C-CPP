# include <iostream>
using namespace std;

//类对象的成员变量、成员函数内存测试 
class Base
{
public:	//成员函数 
	void foo1()	{}
	void foo2()	{}
public:	//成员变量 
	double m_fMember1;
	int m_nMember2;
	long m_nMember3;
	short m_nMember4;
};
 
typedef void (Base::*P) ();	//定义类成员函数指针类型，用于得到类的成员函数指针 
 
int main()
{
	Base base;
	cout<<"类对象的地址是："<<&base<<endl;
	cout<<"类对象成员变量m_fMember1（double）的地址是："<<&(base.m_fMember1)<<endl;
	cout<<"类对象成员变量m_fMember1（double）的占用的内存字节数是："<<sizeof(base.m_fMember1)<<endl;
	cout<<"类对象成员变量m_nMember2（int）的地址是："<<&(base.m_nMember2)<<endl;
	cout<<"类对象成员变量m_nMember3（long）的地址是："<<&(base.m_nMember3)<<endl;
	cout<<"类对象成员变量m_nMember4（short）的地址是："<<&(base.m_nMember4)<<endl;
    
	
	
//	cout<<"Base类第一个成员函数的地址是："<<&Base::foo1<<endl;
//	cout<<"Base类第二个成员函数的地址是："<<&Base::foo2<<endl;
 
	P pFunc = &Base::foo1;
	unsigned int* tmp = (unsigned*) &pFunc;
	cout<<"Base类第一个成员函数的地址是："<<hex<<*tmp<<endl;
	pFunc = &Base::foo2;
	tmp = (unsigned*)&pFunc;
	cout<<"Base类第二个成员函数的地址是："<<hex<<*tmp<<endl;
    cout<< (int)&(base.m_nMember4) - (int)&(base.m_fMember1)<<endl;
    cout<< sizeof(base)<<endl;
	system("pause");
	return 0;
} 
/*
类对象的地址是：0012FF30
类对象成员变量m_fMember1（double）的地址是：0012FF30
类对象成员变量m_fMember1（double）的占用的内存字节数是：8
类对象成员变量m_nMember2（int）的地址是：0012FF38
类对象成员变量m_nMember3（long）的地址是：0012FF3C
类对象成员变量m_nMember4（short）的地址是：0012FF40
Base类第一个成员函数的地址是：4012a3
Base类第二个成员函数的地址是：401127
*/