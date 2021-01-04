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
 
	Resource* nudePtr(new Resource);// 裸指针
	delete nudePtr; //如果忘记delete，则nudePtr超出作用域时自动释放，
	// 释放的是自身，其指向的动态内存却再也没有机会释放，造成动态内存泄漏
	// res2超出作用域时会自动在栈上释放，同时会调用析构函数，delete m_ptr，释放堆上内存
	// 封装的指针（智能指针）在释放自身（栈）的同时释放了其成员指针指向的动态内存（堆内存）
	// 裸指针释放自身（栈）的同时却让其指向的动态内存失去了释放的机会（如果没有delete）
	// delete的不是nudePtr本身（本身超出作用域会自动在栈上释放），
	// delete针对的是其指向的堆内存，其实本质上也没有delete，只是标识为可重新链接的堆内存。
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