#include<iostream>
#include<string>
using namespace std;

template <class T>
class AutoPtr
{
public:
    //���캯��
    AutoPtr(T* ptr = NULL)
        :_ptr(ptr)
    {}
    //��������
    AutoPtr(AutoPtr<T>& ap)
    {
        //����Ȩת��
        _ptr = ap._ptr;
        ap._ptr = NULL;
    }
    //��ֵ���������
    AutoPtr<T>& operator = (AutoPtr<T>& ap)
    {
        if(_ptr != ap._ptr)
        {
            if(_ptr)
            {
                delete _ptr;
            }
            //����Ȩת��
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

    //��������
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