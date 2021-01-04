#include <iostream>
using namespace std;

class A
{
public:
    A(int _a1 = 1) : a1(_a1) { }
    virtual void f() { cout << "A::f" << endl; }
    virtual void g() { cout << "A::g" << endl; }
    virtual void h() { cout << "A::h" << endl; }
    ~A() {}
private:
    int a1;
};

class C : public A
{
public:
    C(int _a1 = 1, int _c = 4) :A(_a1), c(_c) { }
    virtual void f() { cout << "C::f" << endl; }
    virtual void g() { cout << "C::g" << endl; }
    virtual void h() { cout << "C::h" << endl; }
private:
    int c;
};

// ͨ��������C��ǰ4�ֽڣ�32λ���������ҵ��麯������һ�α����麯�����ɡ�
// �麯�������һ���õ���0�������麯���������
typedef void(*FUNC)();        //�ض��庯��ָ�룬ָ������ָ��
void PrintVTable(long* vTable)  //��ӡ�麯����
{
    if (vTable == NULL)
    {
        return;
    }
    cout << "vtbl:" << vTable << endl;
    int  i = 0;
    for (; vTable[i] != 0; ++i)
    {
        printf("function : %d :0X%x->", i, vTable[i]);
        FUNC f = (FUNC)vTable[i];
        f();         //�����麯��
    }
    cout << endl;
}
void main()
{
	A a1;
	long *p = (long *)(*(long*)&a1);
	PrintVTable(p);

	C c;
	long *p2 = (long *)(*(long*)&c);
	PrintVTable(p2);

	system("pause");
}

/*
vtbl:00471048
function : 0 :0X40105a->A::f
function : 1 :0X4012c6->A::g
function : 2 :0X4010b9->A::h

vtbl:00471070
function : 0 :0X4010eb->C::f
function : 1 :0X4011d1->C::g
function : 2 :0X401280->C::h
*/