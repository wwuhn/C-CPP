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
	//...��������ԭ��
private:
	int X, int Y;
	char *p;
};

//�����ǹ��캯��������������ʵ�֣�
Point::Point(int xx,int yy)
{     
	X=xx;   
	Y=yy;
	p=new char[20];     // ���캯���ж�̬����char���ڴ�
}

void Point::show()
{
	cout<<X<<"."<<Y<<endl;
}

Point::~Point()
{
	delete [] p;      // ��������ʱ�ͷ�֮ǰ��̬������ڴ�
}

void main()
{
	Point point(3,4);
	point.show();
    system("pause");
}
