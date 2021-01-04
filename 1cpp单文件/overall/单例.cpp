#include <iostream>
using namespace std; 

class Singleton 
{ 
public :    
	static Singleton * GetInstance() // ��̬��Ա��������һ��ʵ��  
	{
		// Lock(); // ���߳�ʱ(Boost��֧��Lock����)        
		if (m_Instance == NULL)        
		{            
			m_Instance = new Singleton(); // ��        
		}
		// UnLock();// static Singleton m_Instance;  // �� ���߳�ʱ        
		return m_Instance;
		// return const_cast <Singleton *>(m_Instance); // �� ��������ֻ��һ�δ����Ļ���
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
	Singleton(){ m_Test = 10; }                 // ���캯��˽��  
	Singleton::Singleton(const Singleton&) {}   // �������캯��˽��  
	Singleton &Singleton::operator=(const Singleton&) {} // ��ֵ�����˽��    
	static Singleton* m_Instance; // ��̬���ݳ�Ա�����ж��Ƿ������ʵ��    
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
