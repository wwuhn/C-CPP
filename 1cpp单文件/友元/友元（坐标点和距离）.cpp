#include <iostream.h>
#include <math.h>

const double PI = 3.14159;

class Point
{
	double x,y;									// Ĭ��Ϊ˽�г�Ա
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
	friend double distance(Point &a, Point &b);	// ������Ԫ����
	friend class Circle;						// ������Ԫ��
};
												// ʵ����Ԫ����
double distance (Point &a,Point &b)				// �����������Ϊ�β�
{
	double dx = a.x-b.x;						// ���ʶ����˽�г�Ա
	double dy = a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

class Circle									// ��Ԫ���������ʵ��
{
	double cir;
public:
	void circum(Point a,Point b)				// ���������Ϊ�β�
	{
		double dx = a.x-b.x;					// ���ʶ����˽�г�Ա
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

	double d = distance(p1,p2);					// ������Ԫ����
	cout<<"p1��p2�ľ���="<<d<<endl;

	Circle c;
	c.circum(p1,p2);
	cin.get();
}
/*
p1:(2,2)
p2:(5,6)
p1��p2�ľ���=5
the circumstance of circle is 15.708
*/