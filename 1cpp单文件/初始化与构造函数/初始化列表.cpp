#if(0)
#include <iostream>
using namespace std;

class Cb // 无默认构造函数
{
public:
    Cb (int x)
    {
        i = x;   
    }
private:
    int i;
};

class Base
{
	int b;
public:
	Base(int i):b(i){}
};

class Derive:public Base
{
public:
	Derive(int base,int cbi, int cc,int rr,int j) : Base(base),cb(cbi),c(cc),r(rr)
	{
		mvar = j;
	}
private:
    Cb cb;
    int mvar;
	const int c;
    int& r;
};

int main( )
{
	int i = 6;
    Derive(2,3,4,i,5);
    return 0;
}
#endif

#if(1)
#include <iostream>
using namespace std;

class Cb // 无默认构造函数
{
public:
    Cb (int x)
    {
        i = x;   
    }
private:
    int i;
};

class Base
{
	int b;
public:
	Base(int i):b(i){}
	Base(){b=5;}
};

class Derive:public Base
{
public:
	Derive(int base,int cbi, int cc,int rr,int j) : cb(cbi),c(cc),r(rr)
	{
		Base();
		mvar = j;
	}
private:
    Cb cb;
    int mvar;
	const int c;
    int& r;
};

int main( )
{
	int i = 6;
    Derive(2,3,4,i,5);
    return 0;
}
#endif