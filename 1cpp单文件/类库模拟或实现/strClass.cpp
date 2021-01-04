#include <iostream>
#include "stdlib.h"
#include <string.h>				// 引用C语言字符串操作函数
//using namespace std;			// cannot access private member

using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;

class MyString
{
private:
	char* m_data;									// 一个字符指针作为数据域
public:
	MyString(const char *str =NULL);				// 构造函数（实例初始化）
	MyString(const MyString &strs );				// 拷贝构造函数（用其他实例来初始化一个新实例）
	~MyString();									// 析构函数
	MyString & operator =(const MyString &strs);	// 重载运算符=（非初始化时对这个实例进行赋值调用）
	MyString operator +(const MyString &strs);	    // 重载运算符+
	int getLength();								// 返回长度
public:																// 声明友元函数
	friend istream & operator >>(istream &_in, MyString &strs);		// 友元重载运算符>>
	friend ostream & operator <<(ostream &_out, MyString &strs);	// 友元重载运算符<<
};

MyString::MyString(const char *str) // 构造函数（实例初始化）
{
	if (str == NULL){
		m_data = new char[1];
		*m_data = '\0';
	}
	else{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
	}
}

MyString::~MyString()  
{
	if (m_data)
	{
		delete[] m_data;
		m_data = 0;
	}
}

MyString::MyString(const MyString &strs) // 拷贝构造函数（用其他实例来初始化一个新实例）
{
	if (!strs.m_data) //外边没数据等于0
	{
		m_data = 0;
	}
	m_data = new char[strlen(strs.m_data)+1];
	strcpy(m_data, strs.m_data);
}

MyString & MyString::operator=(const MyString &strs)
{
	if (this != &strs)
	{
		delete[] m_data;
		if (!strs.m_data)
		{
			m_data = 0;
		}
		else{
			m_data = new char[strlen(strs.m_data)+1];
			strcpy(m_data,strs.m_data);
		}
	}
	return *this;
}

int MyString::getLength()
{
	return strlen(m_data);
	
}

//friend
istream & operator >>(istream & _in, MyString & strs)
{
	_in >> strs.m_data;
	return _in;
}

ostream & operator <<(ostream &_out, MyString &strs)
{
	_out << strs.m_data;
	return _out;
}

MyString MyString::operator+(const MyString &strs)
{ //新建一个MyString对象
	MyString newMyString;
	if (!strs.m_data)
	{
		newMyString = *this;
	}
	else if (!m_data)
	{
		newMyString = strs;
	}
	else{
		newMyString.m_data = new char[strlen(m_data)+strlen(strs.m_data)+1];
		strcpy(newMyString.m_data ,m_data);
		strcat(newMyString.m_data,strs.m_data);
	}
	
	return newMyString;
}


int main( )
{ 
	MyString str1 ="wwu";
	int n =str1.getLength(); 
	cout <<str1<<"'s length:"<< n <<endl;
	MyString str2 ="hn";
	cout <<str2<<"'s length:"<<str2.getLength()<<endl;
	
	MyString str3(str1);
	str1 = "wqwu";
	cout <<str3<<"'s lentgh:"<<str3.getLength()<<endl;
	MyString str4 = str1+str2;
	cout<<str4<<"'s length:"<<str4.getLength()<<endl;
	cin.get();
	return 0;
}
/*output:
wwu's length:3
hn's length:2
wwu's lentgh:3
wqwuhn's length:6
*/