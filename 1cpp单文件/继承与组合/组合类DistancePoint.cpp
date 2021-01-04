#include <iostream>
#include <cmath>
using namespace std;

class Point
{ 
public:
	Point(int xx,int yy)   { X=xx; Y=yy; }  // ���캯��
	Point(Point &p);
	int GetX(void)     { return X; }        // ȡX����
	int GetY(void)     { return Y; }        // ȡY����
private:
	int X,Y; //�������
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	cout << "Point�������캯��������" << endl;
}

class Distance
{
public:
	Distance(Point a,Point b); //���캯��
	double GetDis()   { return dist; }
private:
	Point  p1,p2;
	double dist;               // ����
};

// �����Ĺ��캯��
Distance::Distance(Point a, Point b):p1(a),p2(b)
{
	cout << "Distance���캯��������" << endl;
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
Point�������캯��������
Point�������캯��������
Point�������캯��������
Point�������캯��������
Distance���캯��������
The distance is:5
*/