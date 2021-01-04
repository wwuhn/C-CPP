#include <iostream>
using namespace std;

class CB
{
public:
	int a;
	int b;
	mutable int c;

	CB(){
		a=10;
		b=100;
	}
};

void foo()
{
	const CB cb;
	//cb.a=1;
	//cb.b=2;
	cb.c=3; //OK
}

void main()
{

	
	
    system("pause");
}
