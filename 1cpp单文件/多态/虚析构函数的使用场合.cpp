#include <iostream>
using namespace std;

class Base
{  
public:  
	virtual ~Base()
	//~Base()
	{
		cout << "~Base()" << endl;  
	}  
};  

//������
class Derived1 : public Base {  
public:  
	Derived1():m_var(new string("NULL")) {}  
	Derived1(const string& var):m_var(new string(var)) {}  
	
	~Derived1() {
		delete m_var;  
		cout << "~Derived1(): m_var has been deleted." << endl;  
	}  	
private:  
	string* m_var;  
};  

class Derived2 : public Base {  
public:  
	Derived2():m_var(new string("NULL")) {}  
	Derived2(const string& n):m_var(new string(n)) {}  	
	~Derived2() {  
		delete m_var;  
		cout << "~Derived2(): m_var has been deleted." << endl;  
	}  
	
private:  
	string* m_var;  
}; 


#if(1)//����1
int main() {  
	Derived1* d1 = new Derived1();  
	//d1ΪDerived1���ָ�룬��ָ��һ���ڶ��ϴ�����Derived1�Ķ���
	//��Ҫ������ʽ����delete����������������
	{Derived2 d2 = Derived2("Bob");  }
	//d2Ϊһ����ջ�ϴ����Ķ���
	//d2���������������ڽ���ʱ��ϵͳ���Զ�����������������
	delete d1;  
	system("pause");
	return 0;    
}
/*
ָ���������������һ�£����������ࣩʱ���������������Ƿ���virtualû�й�ϵ
output:
~Derived2(): m_var has been deleted.
~Base()
~Derived1(): m_var has been deleted.
~Base()
*/
#endif

#if(0)//����2
int main() {  
	Base* base[2] = {  
		new Derived1(),  
		new Derived2("Bob")        
	};  
	for (int i = 0; i != 2; ++i) {  
		delete base[i];      
	}  
	system("pause");
	return 0;  
} 
/*
//������ָ��ָ�����������ʱ���������������Ƿ���virtual���й�ϵ��
output(��������δ����Ϊvirtualʱ):
~Base()
~Base()

output(������������Ϊvirtualʱ):
~Derived1(): m_var has been deleted.
~Base()
~Derived2(): m_var has been deleted.
~Base()
*/
#endif
