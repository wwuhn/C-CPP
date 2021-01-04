#include <iostream>

using namespace std;

class A {
public:
	A() : m_data1(0), m_data2(0) {}
	virtual void vfunc1() { cout << "A::vfunc1" << endl; };
    virtual void vfunc2() { cout << "A::vfunc2" << endl; };
    void func1() { cout << "A::func1" << endl; };
    void func2() { cout << "A::func2" << endl; };
private:
    int m_data1, m_data2;
};

class B : public A {
public:
	B() : A(), m_data3(0) {}
    virtual void vfunc1() { cout << "B::vfunc1" << endl; };
    void func1() { cout << "B::func1" << endl; };
private:
    int m_data3;
};

class C: public B {
public:
	C() : B(), m_data1(0), m_data4(0) {}
    virtual void vfunc2() { cout << "C::vfunc2" << endl; };
    void func2() { cout << "C::func2" << endl; };
private:
    int m_data1, m_data4;
};

int main()
{
	
    A *p;
	A aObject;
	p = &aObject;
	p->vfunc1();
	
	B bObject;
	p = &bObject;
	p->vfunc1();
	
	C cObject;
	p = &cObject;
	p->vfunc1();
	p->vfunc2();
	
	cObject.A::func1();
	aObject = static_cast<A>(bObject); 
	aObject.vfunc1();
/*
	B* bp = &bObject;
	C* cp = &cObject;
	cp = static_cast<C*>(bp);//�����μ��������ת��(ָ��)ʱ��dynamic_cast��static_cast��Ч����һ���ģ�
	//�ڽ�������ת��(ָ��)ʱ��dynamic_cast�������ͼ��Ĺ��ܣ���static_cast����ȫ��
	cp->vfunc1(); //B::vfunc1
	dynamic_cast<C*>(bp); //vc6�������ߵļ�������������
	cp->vfunc1(); //B::vfunc1
*/
	system("pause");
	return 0;
}
/*
A::vfunc1
B::vfunc1
B::vfunc1
C::vfunc2
A::func1
A::vfunc1
*/
