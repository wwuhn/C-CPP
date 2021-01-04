#include <iostream>
using namespace std;
template <typename T>

class mymax
{
public:
	T operator()(T a, T b)	// 重载“()”操作符，在这个操作符中实现具体功能
	{
		return a>b?a:b;
	}
};	
						    // 重载“()”操作符后的类成为一个函数对象
template <typename T>		// 利用函数对象定义函数模板，可以理解为函数指针作为回调函数
T compare(T a, T b, mymax<T>& op)
{
	return op(a,b);			// 利用传递进来的函数对象进行具体的比较操作
}

void main()
{
	mymax<int> intmax;		// 定义一个int类型的函数对象
	int nMax = intmax(3,4);	//直接使用函数对象
	// 编译器行为：int nMax = intmax.operator()(3,4);
	cout<<nMax<<endl;
	nMax = compare(5,6,intmax);//将函数对象作为参数传递给其他函数
	cout<<nMax<<endl;
	system("pause");
}
/*
4
6
*/