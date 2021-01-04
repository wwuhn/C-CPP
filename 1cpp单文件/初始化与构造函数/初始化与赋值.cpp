#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class Base
{
private:
    int n;

public:
    Base(int m):n(m){ cout<<"Base is called\n";}
    ~Base(){}
};

class Other
{
    int m;
public:
    Other(int a):m(a){ cout<<"Other is called\n";}
};

class Derive:public Base
{
    int v;
    const int cst;
    int &r;
    Other obj;
public:
    Derive(int a,int b,int c):Base(a),obj(b),cst(c),r(a)
    {
        v = a;
        cout<<"Self is called\n";
    }
    ~Derive(){}
};


int main()
{
    Derive dd(3,4,5);
int a = 5; // 声明、定义变量的同时初始化
int b(6);  // 声明、定义变量的同时初始化
a = 6;     // 赋值操作，用于变量的更新
b = 7;     // 赋值操作，用于变量的更新
const int c = 8; // 因为是只读，此后不能再更新，自然需要在声明、定义的同时初始化
                 // const在C中是只读变量，C++视上下文可以实现为只读变量或常量
int arr[5]; // 虽然arr有常量性质，但其元素却是可写的变量
int &r = a; // 引用可以理解为一个实现了自动解引用的有常量性质的指针
    
    cout<< 1 <<endl;

    while(1);
    return 0;
}
/*
Base is called
Other is called
Self is called
*/