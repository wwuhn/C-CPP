# include <iostream>
using namespace std;

//�����ĳ�Ա��������Ա�����ڴ���� 
class Base
{
public:	//��Ա���� 
	void foo1()	{}
	void foo2()	{}
public:	//��Ա���� 
	double m_fMember1;
	int m_nMember2;
	long m_nMember3;
	short m_nMember4;
};
 
typedef void (Base::*P) ();	//�������Ա����ָ�����ͣ����ڵõ���ĳ�Ա����ָ�� 
 
int main()
{
	Base base;
	cout<<"�����ĵ�ַ�ǣ�"<<&base<<endl;
	cout<<"������Ա����m_fMember1��double���ĵ�ַ�ǣ�"<<&(base.m_fMember1)<<endl;
	cout<<"������Ա����m_fMember1��double����ռ�õ��ڴ��ֽ����ǣ�"<<sizeof(base.m_fMember1)<<endl;
	cout<<"������Ա����m_nMember2��int���ĵ�ַ�ǣ�"<<&(base.m_nMember2)<<endl;
	cout<<"������Ա����m_nMember3��long���ĵ�ַ�ǣ�"<<&(base.m_nMember3)<<endl;
	cout<<"������Ա����m_nMember4��short���ĵ�ַ�ǣ�"<<&(base.m_nMember4)<<endl;
    
	
	
//	cout<<"Base���һ����Ա�����ĵ�ַ�ǣ�"<<&Base::foo1<<endl;
//	cout<<"Base��ڶ�����Ա�����ĵ�ַ�ǣ�"<<&Base::foo2<<endl;
 
	P pFunc = &Base::foo1;
	unsigned int* tmp = (unsigned*) &pFunc;
	cout<<"Base���һ����Ա�����ĵ�ַ�ǣ�"<<hex<<*tmp<<endl;
	pFunc = &Base::foo2;
	tmp = (unsigned*)&pFunc;
	cout<<"Base��ڶ�����Ա�����ĵ�ַ�ǣ�"<<hex<<*tmp<<endl;
    cout<< (int)&(base.m_nMember4) - (int)&(base.m_fMember1)<<endl;
    cout<< sizeof(base)<<endl;
	system("pause");
	return 0;
} 
/*
�����ĵ�ַ�ǣ�0012FF30
������Ա����m_fMember1��double���ĵ�ַ�ǣ�0012FF30
������Ա����m_fMember1��double����ռ�õ��ڴ��ֽ����ǣ�8
������Ա����m_nMember2��int���ĵ�ַ�ǣ�0012FF38
������Ա����m_nMember3��long���ĵ�ַ�ǣ�0012FF3C
������Ա����m_nMember4��short���ĵ�ַ�ǣ�0012FF40
Base���һ����Ա�����ĵ�ַ�ǣ�4012a3
Base��ڶ�����Ա�����ĵ�ַ�ǣ�401127
*/