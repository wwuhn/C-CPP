#include <iostream>
using namespace std;

struct MyPtr
{
	explicit MyPtr(int value)           // ����
		:ptr(new int(value)){}

	explicit MyPtr(MyPtr const& other)  // ��������
		:ptr(new int(*other.ptr)){}

	//MyPtr(MyPtr const&)=delete;   // ���ÿ�������

/*
	MyPtr(MyPtr const& other)       // ǳ����
	    :ptr(other.ptr){}
*/

	MyPtr(MyPtr&& other) // ת�ƹ���
		:ptr(other.ptr)
	{
		other.ptr = nullptr;
	}
/*
    ת�ƹ�����ǳ��������
    ���߶��ǽ�����ָ���Ա��ָ�򡣵���ת�ƹ������һ����Դָ���ÿյĲ�����
    ��������¾ɶ����е�ָ���Աָ��ͬһ���ڴ�
*/
	MyPtr& operator=(MyPtr const& other) // ��ֵ����������
	{
		if(ptr!=other.ptr)
		{
			delete ptr;
			ptr = new int(*other.ptr);
			//*ptr=*other.ptr;
		}
		return *this;
	}

	//MyPtr& operator=(MyPtr const&)=delete; // ���ø�ֵ����������

	MyPtr& operator=(MyPtr&& other)  // ת�Ƹ�ֵ
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
