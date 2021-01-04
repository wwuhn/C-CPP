#include<iostream.h>

//using namespace std;
class String;
class String
{
	friend String operator+(const String &s1, const String &s2);
	friend ostream &operator<<(ostream &os, const String &obj);
	friend istream &operator>>(istream &is, String &obj);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator>=(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend bool operator!=(const String &s1, const String &s2);
	friend bool operator<(const String &s1, const String &s2);
	friend bool operator<=(const String &s1, const String &s2);
private:
	int len;
	char *data;
public:
	String(const char *s = "");
	String(const String &other);
	String &operator+=(const String &other);
	String &operator=(const String &other);
	String operator()(int start, int end);
	char &operator[](int index) { return data[index];}
	~String() { delete data; }
};

String::String(const char *s)
{
	for (len = 0; s[len] != 0; ++len);
	data = new char[len + 1];
	for (int i = 0; i < len; ++i) 
		data[i] = s[i];
	data[len] = '\0';
}

String::String(const String &s)
{
	len = s.len;
	data = new char[len + 1];
	for (int i = 0; i < len; ++i) data[i] = s.data[i];
	data[len] = '\0';
}

String &String::operator=(const String &other)
{
	if (this == &other) 
		return *this;
	delete data;
	len = other.len;
	data = new char[len + 1];
	for (int i = 0; i < len; ++i) data[i] = other.data[i];
	data[len] = '\0';
	return *this;
}

bool operator>(const String &s1, const String &s2)//全局、友元
{
	for (int i = 0; i < s1.len; ++i) 
	{
		if (s1.data[i] > s2.data[i]) return true;
		if (s1.data[i] < s2.data[i]) return false;
	}
	return false;
}

bool operator>=(const String &s1, const String &s2)
{
	for (int i = 0; i < s1.len; ++i) {
		if (s1.data[i] > s2.data[i]) return true;
		if (s1.data[i] < s2.data[i]) return false;
	}
	return true;
}

bool operator==(const String &s1, const String &s2)
{
	if (s1.len != s2.len) return false;
	for (int i = 0; i < s1.len; ++i)
		if (s1.data[i] != s2.data[i]) return false;
		return true;
}

bool operator!=(const String &s1, const String &s2)
{ return !(s1 == s2); }

bool operator<(const String &s1, const String &s2)
{ return !(s1 >= s2); }

bool operator<=(const String &s1, const String &s2)
{ return !(s1 > s2); }

//字符串的连接用+和+=重载来实现。
String &String::operator+=(const String &other)
{
	char *tmp = data;
	int i;
	data = new char[len + other.len + 1];
	for (i = 0; i < len; ++i) 
		data[i] = tmp[i];
	for (i = 0; i < other.len; ++i) 
		data[len + i] = other.data[i];
	len += other.len;
	data[len] = '\0';
	return *this;
}

String operator+(const String &s1, const String &s2)
{
	String tmp(s1);
	tmp += s2;
	return tmp;
}

//取子串的功能用函数调用运算符重载来实现。
String String::operator()(int start, int end)
{
	if (start > end || start < 0 || end >= len) 
		return String("");
	String tmp;
	delete tmp.data;
	tmp.len = end - start + 1;
	tmp.data = new char[len + 1];
	for (int i = 0; i <= end - start; ++i) 
		tmp.data[i] = data[i + start];
	tmp.data[i] = '\0';
	return tmp;
}

//输出重载的实现比较容易。输出一个String类的对象就是输出它的data值。
//输入重载有些麻烦，因为我们不知道用户输入的字符串有多长，无法为data申请合适的空间。
//输入重载采用了一个块状链表作为过渡。
ostream &operator<<(ostream &os, const String &obj)
{
	os << obj.data;
	return os;
}

istream &operator>>(istream &is, String &obj)
{
	struct Node { // 块状链表的结点类
		char ch[10];
		Node *next;
	};
	Node *head, *tail, *p; // head：块状链表的首指针，tail：块状链表的尾指针
	int len = 0, i;
	head = tail = new Node;
	while ((tail->ch[len % 10] = is.get()) != '\n') { // 输入一个字符存入尾结点
		++len;
		if (len % 10 == 0) { // 申请一个新结点
			tail->next = new Node;
			tail = tail->next;
		}
	}
	obj.len = len;
	delete obj.data;
	obj.data = new char[len + 1];
	for (i = 0; i < len; ++i) { // 将块状链表的内容复制到data
		obj.data[i] = head->ch[i % 10];
		if (i % 10 == 9) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	delete head;
	obj.data[len] = '\0';
	return is;
}

void main()
{
	String str = "abc";
    String ss(str);
    ss += "def"; 
	cout<<ss<<endl;
	while(1);
}

