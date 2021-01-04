#include<iostream>
using namespace std;

class Food
{
public:
	Food()
	{
		cout<<"调用默认构造函数"<<endl;
	}
	Food(Food& other)
	{
		cout<<"调用拷贝构造函数"<<endl;
	}
	Food& operator=(Food& other)
	{
		cout<<"调用赋值操作符"<<endl;
		return other;
	}
};

class Dog
{
	Food m_food;
public:
	//Dog(Food& food):m_food(food){} //调用默认构造函数,使用初始化列表不需再调用赋值操作符了
	//对于内置类型，使用初始化列表与构造函数初始化是一样的
	Dog(Food& food)//调用默认构造函数
	{
		m_food = food;//调用赋值操作符
	}
};

void main()
{
	Food f;
	Dog d(f);

    system("pause");
}
/*
调用默认构造函数
调用默认构造函数
调用赋值操作符
*/