#include <iostream.h>
#include <math.h>

const double PI = 3.14159;

class Point
{
	double x,y;									// 默认为私有成员
public:
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	void display()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	friend double distance(Point &a, Point &b);	// 声明友元函数
	friend class Circle;						// 声明友元类
};
												// 实现友元函数
double distance (Point &a,Point &b)				// 引用类对象作为形参
{
	double dx = a.x-b.x;						// 访问对象的私有成员
	double dy = a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

class Circle									// 友元类的声明和实现
{
	double cir;
public:
	void circum(Point a,Point b)				// 用类对象作为形参
	{
		double dx = a.x-b.x;					// 访问对象的私有成员
		double dy = a.y-b.y;
		cir = PI * sqrt(dx*dx+dy*dy);	
		cout<<"the circumstance of circle is "<<cir<<endl;
	}
};

void main()
{
	Point p1(2.0,2.0), p2(5.0,6.0);
	cout<<"p1:";
	p1.display();
	cout<<"p2:";
	p2.display();

	double d = distance(p1,p2);					// 调用友元函数
	cout<<"p1和p2的距离="<<d<<endl;

	Circle c;
	c.circum(p1,p2);
	cin.get();
}
/*
p1:(2,2)
p2:(5,6)
p1和p2的距离=5
the circumstance of circle is 15.708
*/