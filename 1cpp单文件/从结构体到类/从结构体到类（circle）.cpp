#if 0

#include <iostream>
using namespace std;

struct circle  // �ṹ�������
{
	double x,y;
	double r;
};

void create(circle &c,double xx,double yy,double rr)
{
	c.x=xx;
	c.y=yy;
	c.r=rr;
}

void draw(circle &c)
{
	cout<<"circle:r="<<c.r<<",center@("<<c.x<<","<<c.y<<")"<<endl;
}

double area(circle &c)
{
	return 3.14*c.r*c.r;
}


int main()
{ 
	struct circle c;  // �ṹ�����
	create(c,0,0,3);
	draw(c);
	cout<<"area="<<area(c)<<endl;
	cin.get();
    return 0;
}

#else

#include <iostream>
using namespace std;

class circle  //��������Ͷ���
{
private:
	double x,y;
	double r;
public:
	void create(double xx,double yy,double rr)
	{
		x=xx;
		y=yy;
		r=rr;
	}
/*
    circle(int a,int b,int c:x(a),x(b)  // ���캯��
    {
        r = c;
     }
    
*/
	void draw()
	{
		cout<<"circle:r="<<r<<",center@("<<x<<","<<y<<")"<<endl;
	}

	double area()
	{
		return 3.14*r*r;
	}
};

int main()
{ 
	circle c;  // ���ʵ����
	c.create(0,0,3);
	c.draw();
	cout<<"area="<<c.area()<<endl;
	cin.get();
    return 0;
}

#endif