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

//派生类
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


#if(1)//测试1
int main() {  
	Derived1* d1 = new Derived1();  
	//d1为Derived1类的指针，它指向一个在堆上创建的Derived1的对象；
	//需要我们显式的用delete调用其析构函数；
	{Derived2 d2 = Derived2("Bob");  }
	//d2为一个在栈上创建的对象。
	//d2对象在其生命周期结束时，系统会自动调用其析构函数。
	delete d1;  
	system("pause");
	return 0;    
}
/*
指针类型与对象类型一致（都是派生类）时，基类析构函数是否有virtual没有关系
output:
~Derived2(): m_var has been deleted.
~Base()
~Derived1(): m_var has been deleted.
~Base()
*/
#endif

#if(0)//测试2
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
//当基类指针指向派生类对象时，基类析构函数是否有virtual是有关系的
output(当基函数未申请为virtual时):
~Base()
~Base()

output(当基函数申请为virtual时):
~Derived1(): m_var has been deleted.
~Base()
~Derived2(): m_var has been deleted.
~Base()
*/
#endif
