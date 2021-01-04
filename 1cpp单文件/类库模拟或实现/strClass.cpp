#include <iostream>
#include "stdlib.h"
#include <string.h>				// ����C�����ַ�����������
//using namespace std;			// cannot access private member

using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;

class MyString
{
private:
	char* m_data;									// һ���ַ�ָ����Ϊ������
public:
	MyString(const char *str =NULL);				// ���캯����ʵ����ʼ����
	MyString(const MyString &strs );				// �������캯����������ʵ������ʼ��һ����ʵ����
	~MyString();									// ��������
	MyString & operator =(const MyString &strs);	// ���������=���ǳ�ʼ��ʱ�����ʵ�����и�ֵ���ã�
	MyString operator +(const MyString &strs);	    // ���������+
	int getLength();								// ���س���
public:																// ������Ԫ����
	friend istream & operator >>(istream &_in, MyString &strs);		// ��Ԫ���������>>
	friend ostream & operator <<(ostream &_out, MyString &strs);	// ��Ԫ���������<<
};

MyString::MyString(const char *str) // ���캯����ʵ����ʼ����
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

MyString::MyString(const MyString &strs) // �������캯����������ʵ������ʼ��һ����ʵ����
{
	if (!strs.m_data) //���û���ݵ���0
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
{ //�½�һ��MyString����
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