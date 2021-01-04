#include <iostream>
using namespace std; 

class Singleton 
{ 
public :    
	static Singleton * GetInstance() // 静态成员函数构造一个实例  
	{
		// Lock(); // 多线程时(Boost库支持Lock操作)        
		if (m_Instance == NULL)        
		{            
			m_Instance = new Singleton(); // ①        
		}
		// UnLock();// static Singleton m_Instance;  // ② 多线程时        
		return m_Instance;
		// return const_cast <Singleton *>(m_Instance); // ③ 常量对象只有一次创建的机会
	}    

	static void DestoryInstance()    
	{        
		if (m_Instance != NULL )        
		{            
			delete m_Instance;            
			m_Instance = NULL ;        
		}    
	}  
    
	// This is just a operation example    
	int GetTest()    
	{        
		return m_Test;    
	}
private:    
	Singleton(){ m_Test = 10; }                 // 构造函数私有  
	Singleton::Singleton(const Singleton&) {}   // 拷贝构造函数私有  
	Singleton &Singleton::operator=(const Singleton&) {} // 赋值运算符私有    
	static Singleton* m_Instance; // 静态数据成员用于判断是否存在类实例    
	int m_Test; // used for test
};

Singleton *Singleton ::m_Instance = NULL;

int main(int argc , char *argv [])
{    
	Singleton *singletonObj = Singleton ::GetInstance();    
	cout<<singletonObj->GetTest()<<endl;  //10  
	Singleton ::DestoryInstance();    
	return 0;
} 
