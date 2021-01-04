#include <iostream>
using namespace std;

template <class T>
class ptr
{
private:
	T *ip;//指针
    int n;
public:
	ptr(int n);
	~ptr();
};

template <class T>
ptr<T>::ptr(int n)
{
    this->n = n;
	ip = new T[n];//初始化
	cout<<"调用指针管理类构造函数"<<endl;
}

template <class T>
ptr<T>::~ptr()
{
	delete [] ip;//释放
    n=0;
	cout<<"指针管理类析构函数被调用"<<endl;
}

void main()
{

	{
		ptr<int> p(10);//自定义指针类对象
	}//超出作用域自动析构，释放指针
	system("pause");
}
/*
调用指针管理类构造函数
指针管理类析构函数被调用
*/