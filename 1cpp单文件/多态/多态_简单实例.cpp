#include <iostream>
using namespace std;

class A								// ����A
{
public:
	virtual void f()				// �麯��
	{
		cout<<"class A"<<endl;
	}
};

class B								// ����B
{
public:
	void f()						// ���麯��
	{
		cout<<"class B"<<endl;
	}
};

class C:public A,public B			//������C������A��B����
{
public:
	void f()						// ��д���ຯ��
	{
		cout<<"class C"<<endl;
	}
};

int main()
{ 
	A a, *pa;							// �������A�Ķ����ָ��
	B b, *pb;							// �������B�Ķ����ָ��
	C c;								// ����������C�Ķ���
	pa =&a;								// �����ָ��ָ��������
	cout<<"����ָ��paָ��������a��";
	pa->f();							// paָ�����a������A���f()
	pa=&c;								// ����ָ��ָ�������������c
	cout<<"����ָ��paָ�������������c��";
	pa->f();							
	// paָ�����C����Ϊ�����f()���麯������ָ��Ķ�����ı䣬���Ե���C���f()
	pb =&b;								// �����ָ��ָ��������
	cout<<"����ָ��pbָ��������b��";
	pb->f();							// pbָ�����b������B���f()
	pb=&c;								//����ָ��ָ�������������c
	cout<<"����ָ��pbָ�������������c��";
	pb->f();
	// pbָ�����C����Ϊ�����f()�����麯��������ָ��Ķ�����ı䣬���Ե���B���f()
	system("pause");
    return 0;
}
/*
����ָ��paָ��������a��class A
����ָ��paָ�������������c��class C
����ָ��pbָ��������b��class B
����ָ��pbָ�������������c��class B
*/