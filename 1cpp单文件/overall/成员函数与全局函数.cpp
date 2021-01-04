#include <iostream>
using namespace std;

class Adder{
	int a,b;
public:
	Adder(int a,int b)
	{
		this->a=a; 
		this->b=b;
	}

	int add(){
		return a+b;
	}

	friend int addf(Adder& adder);
};

int addf(Adder& adder)
{ return adder.a+adder.b;}


class Test{
	int n;
public:
	Test(){}
	Test(int i)
	{ n=i;}
	int getn()
	{ return n;}
	void setn(int j)
	{ n=j;}
	Test add(Test &t2);
	Test& add2(Test &t2);
};

Test Test::add(Test &t2)
{ 
	Test temp(3);
	temp.n += t2.getn();
	return temp;
}

Test& Test::add2(Test &t2)
{ 
	this->n += t2.getn();
	return *this; //*操作让this指针回到元素状态
}

Test add(Test &t1, Test &t2)  // 全局函数
{
	Test temp;
	int n = t1.getn()+t2.getn();
	temp.setn(n);
	return temp;
}

void main()
{
	Adder adder(3,4);
	cout<<adder.add()<<endl;
	cout<<addf(adder)<<endl;
	Test t1(3),t2(4);
	cout<<t1.add(t2).getn()<<endl;
	cout<<add(t1,t2).getn()<<endl;
	cout<<t1.add2(t2).getn();
}
