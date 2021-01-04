#include<iostream>
#include<string>
using namespace std;

template <class T>
class AutoPtr
{
public:
    //构造函数
    AutoPtr(T* ptr = NULL)
        :_ptr(ptr)
    {}
    //拷贝构造
    AutoPtr(AutoPtr<T>& ap)
    {
        //管理权转移
        _ptr = ap._ptr;
        ap._ptr = NULL;
    }
    //赋值运算符重载
    AutoPtr<T>& operator = (AutoPtr<T>& ap)
    {
        if(_ptr != ap._ptr)
        {
            if(_ptr)
            {
                delete _ptr;
            }
            //管理权转移
            _ptr = ap._ptr;
            ap._ptr = NULL;
        }
        return *this;
    }

    T* operator ->()
    {
        return _ptr;
    }

    T& operator *()
    {
        return *_ptr;
    }

    //析构函数
    ~AutoPtr()
    {
        cout<<"~AutoPtr()"<<endl;
        if(_ptr)
        {
            delete _ptr;
        }
    }
private:
    T* _ptr;
};

void TestAutoPtr()
{
    AutoPtr<int> ptr1(new int(10));
    AutoPtr<int> ptr2(ptr1);
    AutoPtr<int> ptr3(ptr2);
    cout<<*ptr3<<endl;

}
int main()
{
    TestAutoPtr();
    return 0;

}