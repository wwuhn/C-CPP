#include <iostream>
 
template<class T>
class Unique_ptr
{
	T* m_ptr;
public:
	Unique_ptr(T* ptr = nullptr):m_ptr(ptr)
	{}
 
	~Unique_ptr()
	{
		delete m_ptr;
	}
 
	// Copy constructor -- no copying allowed!
	Unique_ptr(const Unique_ptr& a) = delete;
 
	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Unique_ptr(Unique_ptr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}
 
	// Copy assignment -- no copying allowed!
	Unique_ptr& operator=(const Unique_ptr& a) = delete;
 
	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Unique_ptr& operator=(Unique_ptr&& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
 
int main()
{
	Unique_ptr<Resource> res1(new Resource);
	Unique_ptr<Resource> res2; // Start as nullptr
 
	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
 
	//res2 = res1; // auto_ptr
 
	Resource* nudePtr(new Resource);// ��ָ��
	delete nudePtr; //�������delete����nudePtr����������ʱ�Զ��ͷţ�
	// �ͷŵ���������ָ��Ķ�̬�ڴ�ȴ��Ҳû�л����ͷţ���ɶ�̬�ڴ�й©
	// res2����������ʱ���Զ���ջ���ͷţ�ͬʱ���������������delete m_ptr���ͷŶ����ڴ�
	// ��װ��ָ�루����ָ�룩���ͷ�����ջ����ͬʱ�ͷ������Աָ��ָ��Ķ�̬�ڴ棨���ڴ棩
	// ��ָ���ͷ�����ջ����ͬʱȴ����ָ��Ķ�̬�ڴ�ʧȥ���ͷŵĻ��ᣨ���û��delete��
	// delete�Ĳ���nudePtr������������������Զ���ջ���ͷţ���
	// delete��Ե�����ָ��Ķ��ڴ棬��ʵ������Ҳû��delete��ֻ�Ǳ�ʶΪ���������ӵĶ��ڴ档
	return 0;
}
/*
Resource acquired                                                                                                     
res1 is not null                                                                                                      
res2 is null                                                                                                          
Resource acquired                                                                                                     
Resource destroyed                                                                                                    
Resource destroyed 
*/