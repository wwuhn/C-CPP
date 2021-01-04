#include <iostream>
#include <memory>
using namespace std;

class Simple
{
public:
	void go(){}
};

void leaky()
{
	Simple* p = new Simple();
	p->go();
	delete p;//如果go()抛出异常，delete得不到执行从而产生内存泄露
}

void notleaky()
{
	unique_ptr<Simple> p(new Simple());
	p->go();
	//delete p;//如果go()抛出异常，delete得不到执行从而产生内存泄露
}

int main()
{	
    system("pause");
	return 0;
}
