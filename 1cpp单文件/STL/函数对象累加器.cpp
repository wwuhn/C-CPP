#include <iostream>
using namespace std;

struct Counter
{
private:
	int base;
public:
	Counter(){base=0;}
	int operator()(){return base;}
	void operator()(int n){base+=n;}
};

int main()
{
	Counter counter;
	for(int i=1; i<=100; i++)
		counter(i);
	cout<<counter()<<endl; //5050
    system("pause");
	return 0;
}
