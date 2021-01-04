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
 
template <class T> // Partial-specializationƫ�ػ���m_valueΪT*��
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
 
template <> //Full specialization�ػ���m_valueΪchar*��
Storage<char*>::Storage(char* value)
{
	// ����value����length
	int length = 0; 
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator
 
	m_value = new char[length]; //Ϊvalue��̬�����ڴ�
 
	for (int count = 0; count < length; ++count) //ֵ�����붯̬�ڴ��
		m_value[count] = value[count];
}
 
template<>		//Full specialization�ػ���������m_valueΪchar*��
Storage<char*>::~Storage()
{
	delete[] m_value;
}

// Full specialization�ػ��ĺ���print()��m_valueΪchar*��
// ���û���ػ������һ��Storage<char*>�����Storage<T*>::print(), ֻ������ַ�
template<>
void Storage<char*>::print()
{
	std::cout << m_value;
}
 
int main()
{
	Storage<int> myint(5); // ���ػ�����ģ�����
	myint.print();  //5
 
	int x = 7;
	Storage<int*> myintptr(&x); // ƫ�ػ�����ģ�����
 
	x = 9;
	myintptr.print(); // ���û��ƫ�ػ�ģ�嶨�壬�����9������7
 
    char *name = new char[40];
    strcpy(name, "Alex");
 	Storage< char*> myname(name);//�ػ�����ģ�����
 	delete[] name;
 	myname.print(); //���Alex
}

# if 0
#include <iostream>
#include <string.h>
using namespace std;

template<typename T> // ��ͨ����ģ��
T Max(T t1,T t2){
    return (t1>t2)?t1:t2;
}
  
typedef const char* CCP;
template<>  // ����ģ���ػ�
CCP Max<CCP>(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

CCP Max(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}
int main(){
    int i=Max(10,5); // ������ͨ����ģ��
    const char* p=Max<const char*>("very","good"); // �����ػ�����ģ��
    cout<<"i:"<<i<<endl; // i:10
    cout<<"p:"<<p<<endl; // p:very
}

#endif