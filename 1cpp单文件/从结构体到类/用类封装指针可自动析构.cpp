#include <iostream>
#include <list>
using namespace std;

int *p;
void foo() // 在特定时机下初始化全局指针
{
    p = new int(9);
}

list<int*> lis;
void f() //做为全局容器的指针元素
{
    int*p = new int(9);
    lis.push_back(p);
}

class SP
{
public:
    char* p;
    
    SP():p(NULL){}
    SP(int n){p = new char[n];}
    ~SP(){ delete[] p;}
};

int main()
{
    char* p = new char[66]; // 在p超出作用域前要显式delete堆内存
    SP sp(66);              // 当sp超出作用域前会隐式调用~sp()
    
    p = "abc";
    sp.p = "defg";
    cout<<p<<endl;
    
    int* pa=new int[665536];
    int n;
    cin >> n;
    int* parr = new int[n];
    system("pause");
    return 0;
}
