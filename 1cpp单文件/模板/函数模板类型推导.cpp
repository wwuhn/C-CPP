#include <stdio.h>
#include <iostream>

using namespace std;

//此函数中并不知道iter所指的元素型别，而是通过模板T来获取的
template <class I, class T1 ,class T>
T sum_impl(I iter ,T1 n , T t) {
    T sum = 0;//通过模板的特性，可以获取I所指之物的型别，此处为int

    //这里做func应该做的工作
    for(int i = 0 ; i < n ;i++){
        sum+=*iter++;
    } 
    return sum;
}

template <class I , class T1>
inline T1 sum(I iter , T1 n) {//此处暴露了template参数推导机制的缺陷，在型别用于返回值时便束手无策
    return sum_impl(iter , n ,*iter);
}

int main() {
    int a[5] = {1,2,3,4,5};
    int sum1 = sum(a , 5);
    cout<<sum1<<endl;   // 15
}
