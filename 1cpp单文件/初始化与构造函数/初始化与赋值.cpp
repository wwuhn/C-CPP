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
int a = 5; // ���������������ͬʱ��ʼ��
int b(6);  // ���������������ͬʱ��ʼ��
a = 6;     // ��ֵ���������ڱ����ĸ���
b = 7;     // ��ֵ���������ڱ����ĸ���
const int c = 8; // ��Ϊ��ֻ�����˺����ٸ��£���Ȼ��Ҫ�������������ͬʱ��ʼ��
                 // const��C����ֻ��������C++�������Ŀ���ʵ��Ϊֻ����������
int arr[5]; // ��Ȼarr�г������ʣ�����Ԫ��ȴ�ǿ�д�ı���
int &r = a; // ���ÿ������Ϊһ��ʵ�����Զ������õ��г������ʵ�ָ��
    
    cout<< 1 <<endl;

    while(1);
    return 0;
}
/*
Base is called
Other is called
Self is called
*/