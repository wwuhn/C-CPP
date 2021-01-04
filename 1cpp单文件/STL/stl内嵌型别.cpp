#include <iostream>
using namespace std;

template <class T>
struct MyIter{
    typedef T value_type; // 内嵌型别声明
    T* ptr;
    MyIter(T* p =0):ptr(p){}
    T& operator*() const {return *ptr;}
};
template <class T>
struct MyIter <T*>{   //T*代表T为原生指针，这便是T为任意型别的一个更进一步的条件限制
    typedef T value_type; // 内嵌型别声明
    T* ptr;
    MyIter(T* p =0):ptr(p){}
    T& operator*() const {return *ptr;}
};

template <class I>
typename I::value_type    // func返回值型别
func(I iter){
    return *iter;
}

int main(){
    MyIter<int> iter(new int(8));
    cout<<func(iter)<<endl;  // 8
}
