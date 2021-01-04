#include <iostream>
 
template<class T>
class Unique_ptr
{
	T* m_ptr;
public:
	Unique_ptr(T* ptr=nullptr)
		:m_ptr(ptr){}
	
	~Unique_ptr()
	{
		delete m_ptr;
	}
 
	// A copy constructor that implements move semantics
	Unique_ptr(Unique_ptr& a) // note: not const
	{
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}
	
	// An assignment operator that implements move semantics
	Unique_ptr& operator=(Unique_ptr& a) // note: not const
	{
		if (&a == this)
			return *this;
 
		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr;  }
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
 
	res2 = res1; // res2 assumes ownership, res1 is set to null
 
	std::cout << "Ownership transferred\n";
 
	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

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
Ownership transferred
res1 is null
res2 is not null
Resource destroyed
*/