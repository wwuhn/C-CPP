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
	cp = static_cast<C*>(bp);//在类层次间进行上行转换(指针)时，dynamic_cast和static_cast的效果是一样的；
	//在进行下行转换(指针)时，dynamic_cast具有类型检查的功能，比static_cast更安全。
	cp->vfunc1(); //B::vfunc1
	dynamic_cast<C*>(bp); //vc6出错，在线的几个编译器都行
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
