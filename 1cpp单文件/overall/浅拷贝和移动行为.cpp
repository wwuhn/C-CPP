#include <iostream>
using namespace std;

struct MyPtr
{
	explicit MyPtr(int value)           // 构造
		:ptr(new int(value)){}

	explicit MyPtr(MyPtr const& other)  // 拷贝构造
		:ptr(new int(*other.ptr)){}

	//MyPtr(MyPtr const&)=delete;   // 禁用拷贝构造

/*
	MyPtr(MyPtr const& other)       // 浅拷贝
	    :ptr(other.ptr){}
*/

	MyPtr(MyPtr&& other) // 转移构造
		:ptr(other.ptr)
	{
		other.ptr = nullptr;
	}
/*
    转移构造与浅拷贝区别：
    两者都是仅复制指针成员的指向。但是转移构造多了一步让源指针置空的操作，
    不会造成新旧对象中的指针成员指向同一块内存
*/
	MyPtr& operator=(MyPtr const& other) // 赋值操作符重载
	{
		if(ptr!=other.ptr)
		{
			delete ptr;
			ptr = new int(*other.ptr);
			//*ptr=*other.ptr;
		}
		return *this;
	}

	//MyPtr& operator=(MyPtr const&)=delete; // 禁用赋值操作符重载

	MyPtr& operator=(MyPtr&& other)  // 转移赋值
	{
	    if(ptr!=other.ptr)
	    {
	        ptr=other.ptr;
	        other.ptr=nullptr;
	    }
	    return *this;
	}

	~MyPtr(){delete ptr;}
	int* ptr;
};

int main()
{
	MyPtr mp(5);
	MyPtr mp2(mp);
	cout<<*mp2.ptr<<endl;
    system("pause");
	return 0;
}
