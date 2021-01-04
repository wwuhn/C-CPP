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
	delete p;//���go()�׳��쳣��delete�ò���ִ�дӶ������ڴ�й¶
}

void notleaky()
{
	unique_ptr<Simple> p(new Simple());
	p->go();
	//delete p;//���go()�׳��쳣��delete�ò���ִ�дӶ������ڴ�й¶
}

int main()
{	
    system("pause");
	return 0;
}
