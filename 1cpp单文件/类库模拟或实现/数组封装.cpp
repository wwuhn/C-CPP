#include <iostream>
using namespace std;
#include <stdlib.h> 

const int DefaultSize = 100; 

template <class Type> 
class Array 
{
    Type *elements;  // �����ſռ�
    int ArraySize;   // ��ǰ���� 
    void getArray(); // ��������ռ�
public:
    Array(int Size=DefaultSize);
    Array(const Array<Type>&x);
    ~Array(){delete[] elements;}
    Array<Type>& operator=(const Array<Type> &A);
    Type& operator[](int i);
    int Length() const{return ArraySize;}
    void Resize(int sz);
};

template <class Type>
void Array<Type>::getArray () // ˽�к��������ڴ����
{
    elements = new Type[ArraySize]; 
    if ( elements == NULL ) 
    { 
        ArraySize = 0;
        cerr << "�洢�������"<< endl;
        return;
    }
}

template <class Type>  // ���캯��
Array<Type>::Array(int sz) 
{
    if(sz <= 0)
    {
        ArraySize = 0;
        cerr << "�Ƿ������С"<< endl; 
        return;
    }
    ArraySize = sz; 
    getArray();
}

template <class Type>  // ���ƹ��캯��
Array<Type>::Array(const Array<Type>& x)
{
    int n = x.ArraySize;
    ArraySize = n; 
    elements  = new Type[n]; 
    if(elements == NULL ) 
    { 
        ArraySize = 0; 
        cerr<<"�洢�������"<<endl; 
        return;
    }
    Type *srcptr  = x.elements;
    Type *destptr = elements;
    while(n--)
        *destptr++ = *srcptr++;
}

template <class Type> 
Type& Array<Type>::operator[](int i) // ������[]����
{
    if(i < 0 || i>ArraySize-1)
    { 
        cerr << "�����±곬��"<< endl;
        return *(Type*)NULL;
    }
    return elements[i];
}

template <class Type> 
void Array<Type> :: Resize ( int sz )  // ������չ
{
    if ( sz >= 0 && sz != ArraySize ) 
    { 
        Type * newarray = new Type [sz];
        if ( newarray == NULL ) 
        {
            cerr << "�洢�������" << endl; 
            return;
        }
        int n=(sz <= ArraySize) ? sz : ArraySize; // ���µĴ�С����Ԫ�ظ���
        Type *srcptr = elements;
            Type *destptr = newarray;
        while ( n-- ) 
            * destptr++ = * srcptr++;
        delete [] elements;
        elements = newarray;
        ArraySize = sz;
        
    }
}

int main()
{
    Array<int> arr(5);
	arr[4] = 44;
	cout<<arr[4]<<endl;
	arr.Resize(9);
	arr[8] = 88;
    cout<<arr[8]<<endl;
    cin.get();
    return 0;
}
/*

*/