#include <stdio.h>
#include <iostream>

using namespace std;

//�˺����в���֪��iter��ָ��Ԫ���ͱ𣬶���ͨ��ģ��T����ȡ��
template <class I, class T1 ,class T>
T sum_impl(I iter ,T1 n , T t) {
    T sum = 0;//ͨ��ģ������ԣ����Ի�ȡI��ָ֮����ͱ𣬴˴�Ϊint

    //������funcӦ�����Ĺ���
    for(int i = 0 ; i < n ;i++){
        sum+=*iter++;
    } 
    return sum;
}

template <class I , class T1>
inline T1 sum(I iter , T1 n) {//�˴���¶��template�����Ƶ����Ƶ�ȱ�ݣ����ͱ����ڷ���ֵʱ�������޲�
    return sum_impl(iter , n ,*iter);
}

int main() {
    int a[5] = {1,2,3,4,5};
    int sum1 = sum(a , 5);
    cout<<sum1<<endl;   // 15
}
