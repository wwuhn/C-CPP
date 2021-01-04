#include <iostream>
#include <cstring>
 
template <class T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
	{
		m_value = value;
	}
 
	~Storage()
	{
	}
 
	void print()
	{
		std::cout << m_value << '\n';
	}
};
 
template <class T> // Partial-specialization偏特化（m_value为T*）
class Storage<T*>
{
private:
	T* m_value;
public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}
 
	~Storage()
	{
		delete m_value;
	}
 
	void print()
	{
		std::cout << *m_value << '\n';
	}
};
 
template <> //Full specialization特化（m_value为char*）
Storage<char*>::Storage(char* value)
{
	// 计算value长度length
	int length = 0; 
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator
 
	m_value = new char[length]; //为value动态分配内存
 
	for (int count = 0; count < length; ++count) //值复制入动态内存块
		m_value[count] = value[count];
}
 
template<>		//Full specialization特化的析构（m_value为char*）
Storage<char*>::~Storage()
{
	delete[] m_value;
}

// Full specialization特化的函数print()（m_value为char*）
// 如果没有特化，输出一个Storage<char*>会调用Storage<T*>::print(), 只输出首字符
template<>
void Storage<char*>::print()
{
	std::cout << m_value;
}
 
int main()
{
	Storage<int> myint(5); // 非特化函数模板调用
	myint.print();  //5
 
	int x = 7;
	Storage<int*> myintptr(&x); // 偏特化函数模板调用
 
	x = 9;
	myintptr.print(); // 如果没有偏特化模板定义，会输出9而不是7
 
    char *name = new char[40];
    strcpy(name, "Alex");
 	Storage< char*> myname(name);//特化函数模板调用
 	delete[] name;
 	myname.print(); //输出Alex
}

# if 0
#include <iostream>
#include <string.h>
using namespace std;

template<typename T> // 普通函数模板
T Max(T t1,T t2){
    return (t1>t2)?t1:t2;
}
  
typedef const char* CCP;
template<>  // 函数模板特化
CCP Max<CCP>(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

CCP Max(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}
int main(){
    int i=Max(10,5); // 调用普通函数模板
    const char* p=Max<const char*>("very","good"); // 调用特化函数模板
    cout<<"i:"<<i<<endl; // i:10
    cout<<"p:"<<p<<endl; // p:very
}

#endif