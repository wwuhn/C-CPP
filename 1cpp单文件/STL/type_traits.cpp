#include <iostream>
using namespace std;

struct True_type {};
struct False_type {}; 

struct A{};
struct B{};

template <class type> 
struct type_traits {
    typedef False_type has_xxx;   // Ĭ��ΪFalse_type
};


template <>  // �ػ�A
struct type_traits<A> {
    typedef True_type has_xxx;
}; 

template <>  // �ػ�B
struct type_traits<B> {
    typedef False_type has_xxx;
}; 

template <class T>
void test(T t) 
{
    typedef typename type_traits<T>::has_xxx  has_x;
    _test(has_x());
};

void _test(True_type) {
    cout << "1" << endl;
}

void _test(False_type) {
    cout << "0" << endl;
}



int main() {
    struct A a;
    struct B b;
    test(a);    // ���1
    test(b);    // ���0
    test(1);    // ���0
    test(3.5);  // ���0
    return 0;
}
// type traits������ȡԪ�����ԣ����Ԫ�ؾ���ĳ��������do_something������do_otherthing��
// ����������������A��B�������ػ���ֻ��A������has_xxx��ĳ�����ʣ�Ϊtrue_type��
// ����test���ݲ���Tʱ��type_traits����������ȡ����T�е�has_xxx �������has_x��
// ��������A�ж�true_type�������has_xxx�����������has_x ����true_type���ͣ����ú���_test��
// ����_test�������汾�����ݲ�������ƥ�䣬����Ϊtrue_type���ͣ����1��
// ����test��b����test��1����test��3.5�����0��һ���ĵ���