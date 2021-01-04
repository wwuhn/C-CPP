#include <iostream>
using namespace std;

struct True_type {};
struct False_type {}; 

struct A{};
struct B{};

template <class type> 
struct type_traits {
    typedef False_type has_xxx;   // 默认为False_type
};


template <>  // 特化A
struct type_traits<A> {
    typedef True_type has_xxx;
}; 

template <>  // 特化B
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
    test(a);    // 输出1
    test(b);    // 输出0
    test(1);    // 输出0
    test(3.5);  // 输出0
    return 0;
}
// type traits用来萃取元素特性，如果元素具有某个性质则do_something，否则do_otherthing。
// 这个例子里对类类型A、B进行了特化，只有A类型里has_xxx（某个性质）为true_type，
// 向函数test传递参数T时，type_traits进行特性萃取，将T中的has_xxx 赋予别名has_x，
// 而在类型A中对true_type赋予别名has_xxx，所以这里的has_x 就是true_type类型，调用函数_test，
// 函数_test有两个版本，根据参数进行匹配，参数为true_type类型，输出1。
// 调用test（b）、test（1）、test（3.5）输出0是一样的道理。