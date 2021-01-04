#include <iostream>
using namespace std;

template<typename T>
class SP
{
public:
	SP():p(NULL){}
	SP(int n){p = new char[n];}
	~SP(){ delete[] p;}
	T& operator*() const
	{ return *px; }
	T* operator->() const
	{ return px; }
	SP(T* p):px(p){}
	// 如果用做迭代器要重载++、--、+n、-n等运算符
private:
	T* px;
	long* pn;
};

int main()
{
	
	
	cout<<""<<endl;
    system("pause");
	return 0;
}
