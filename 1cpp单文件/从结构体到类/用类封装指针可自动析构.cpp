#include <iostream>
#include <list>
using namespace std;

int *p;
void foo() // ���ض�ʱ���³�ʼ��ȫ��ָ��
{
    p = new int(9);
}

list<int*> lis;
void f() //��Ϊȫ��������ָ��Ԫ��
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
    char* p = new char[66]; // ��p����������ǰҪ��ʽdelete���ڴ�
    SP sp(66);              // ��sp����������ǰ����ʽ����~sp()
    
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
