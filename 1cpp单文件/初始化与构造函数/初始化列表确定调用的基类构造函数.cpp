#include<iostream.h>

class one
{
	int x,y;
public:
	one():x(3)
	{cout<<"调用基类无参数构造函数\n";} //没有参数的构造函数
	//one(int a,int b):x(a),y(b)
	//{cout<<"调用基类两个参数的构造函数";}
};

class two:public one
{
public:
	two(){} //因为基类已经定义2个构造,所以应该指定调用哪个
	void disp()
	{
		cout<<"调用two的disp函数"<<endl;
	}
};

void main()
{
	two t;
	t.disp();
	cin.ignore();
}