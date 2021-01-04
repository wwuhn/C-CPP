#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Point
{     
public:
	Point(int xx, int yy);
	void show();
	~Point();
	//...其他函数原型
private:
	int X, int Y;
	char *p;
};

//下面是构造函数和析构函数的实现：
Point::Point(int xx,int yy)
{     
	X=xx;   
	Y=yy;
	p=new char[20];     // 构造函数中动态分配char型内存
}

void Point::show()
{
	cout<<X<<"."<<Y<<endl;
}

Point::~Point()
{
	delete [] p;      // 在类析构时释放之前动态分配的内存
}

void main()
{
	Point point(3,4);
	point.show();
    system("pause");
}
