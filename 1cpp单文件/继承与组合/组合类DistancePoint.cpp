#include <iostream>
#include <cmath>
using namespace std;

class Point
{ 
public:
	Point(int xx,int yy)   { X=xx; Y=yy; }  // 构造函数
	Point(Point &p);
	int GetX(void)     { return X; }        // 取X坐标
	int GetY(void)     { return Y; }        // 取Y坐标
private:
	int X,Y; //点的坐标
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	cout << "Point拷贝构造函数被调用" << endl;
}

class Distance
{
public:
	Distance(Point a,Point b); //构造函数
	double GetDis()   { return dist; }
private:
	Point  p1,p2;
	double dist;               // 距离
};

// 组合类的构造函数
Distance::Distance(Point a, Point b):p1(a),p2(b)
{
	cout << "Distance构造函数被调用" << endl;
	double x = double(p1.GetX() - p2.GetX());
	double y = double(p1.GetY() - p2.GetY());
	dist = sqrt(x*x + y*y);
	return;
}

int main()
{
	Point myp1(1,1), myp2(4,5);
	Distance myd(myp1, myp2);
	cout << "The distance is:";
	cout << myd.GetDis() << endl;
	system("pause");
	return 0;
}
/*
Point拷贝构造函数被调用
Point拷贝构造函数被调用
Point拷贝构造函数被调用
Point拷贝构造函数被调用
Distance构造函数被调用
The distance is:5
*/