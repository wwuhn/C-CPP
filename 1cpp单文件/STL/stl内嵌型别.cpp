#include <iostream>
using namespace std;

template <class T>
struct MyIter{
    typedef T value_type; // ��Ƕ�ͱ�����
    T* ptr;
    MyIter(T* p =0):ptr(p){}
    T& operator*() const {return *ptr;}
};
template <class T>
struct MyIter <T*>{   //T*����TΪԭ��ָ�룬�����TΪ�����ͱ��һ������һ������������
    typedef T value_type; // ��Ƕ�ͱ�����
    T* ptr;
    MyIter(T* p =0):ptr(p){}
    T& operator*() const {return *ptr;}
};

template <class I>
typename I::value_type    // func����ֵ�ͱ�
func(I iter){
    return *iter;
}

int main(){
    MyIter<int> iter(new int(8));
    cout<<func(iter)<<endl;  // 8
}
