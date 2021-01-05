#include <iostream>
#include <string>
using namespace std;

string strFilter(string s)	//需要优化
{
	string ret;
	for(int i=0; i<s.length(); ++i)
		if(s[i] >=0x20)//32，ASCII中，1-32都是控制字符，包括换行、回车符、制表符、空格等；
			ret=ret+s[i];	// 字符串连接符会生成一个临时对象，调用s.length()次内存管理器
							// 来分配内存和释放内存
							// 赋值操作可能还会分配额外的字符串，取决于字符串是如何实现的
	return ret;
}

string strFilter1(string s)	// 1st优化:使用复合赋值操作避免临时字符串
{
	string ret;
	for(int i=0; i<s.length(); ++i)
		if(s[i] >=0x20)
			ret+=s[i];	// 通过使用复合赋值操作，避免字符串连接符操作产生的开销
						// 仍会导致ret变长的操作，会反复地复制到一个更大的内存缓冲区中
	return ret;
}

string strFilter2(string s)	// 2nd优化:通过预留存储空间减少内存的重新分配
{							// 参数复制操作会产生额外开销
	string ret;
	ret.reserve(s.length());
	for(int i=0; i<s.length(); ++i)
		if(s[i] >=0x20)
			ret+=s[i];
	return ret;
}

string strFilter3(string& s)// 3rd优化:使用引用传址，消除对参数字符串的复制
{							
	string ret;
	ret.reserve(s.length());
	for(int i=0; i<s.length(); ++i)
		if(s[i] >=0x20)		// 引用变量是用指针实现的，编译器要实现解引用，这会带来开销
			ret+=s[i];
	return ret;
}

string strFilter4(string& s)// 4th优化:使用迭代器消除引用的自动解引用
							// 字符串的值返回方式会带来开销
{							
	string ret;
	ret.reserve(s.length());
	for(string::iterator it=s.begin(),end=s.end(); it!=end; ++it) 
							//迭代器是简单指针，可以在循环中节省两次解引用操作
		if(*it >=0x20)
			ret+=*it;
	return ret;
}

void strFilter5(string& ret, string& s)	// 5th优化:消除对返回的字符串的复制
							// string对象有安全性，但效率还是不及C风格字符串
{							
	//ret.clear();
	ret.reserve(s.length());
	for(string::iterator it=s.begin(),end=s.end(); it!=end; ++it) 
		if(*it >=0x20)
			ret+=*it;
}

void strFilter6(char* destp, char const* srcp)	// 6th优化:使用C风格字符串
{												// 单个字符串操作导致了最差的内存分配行为
	char* p=destp;
	while(*srcp!='\0')
	{
		if(*srcp>=0x20)
			*p++ = *srcp;
		srcp++;
	}
	*p = '\0';
}
string strFilter7(string s)	// 7th优化:算法优化，通过子字符串移动减少外层循环
{							
	string ret;
	for(size_t b=0,i=b,e=s.length(); b<e; b=i+1)
	{
		for(i=b;i<e;++i)
		{
			if(s[i]<0x20)
				break;
		}
		ret=ret+s.substr(b,i-b); // 字符串连接符产生临时字符串，影响性能
	}
	return ret;
}

string strFilter8(string s)	//8th算法优化，用append()成员方法复制，无需创建临时字符串
{							
	string ret;
	for(size_t b=0,i=b,e=s.length(); b<e; b=i+1)
	{
		for(i=b;i<e;++i)
		{
			if(s[i]<0x20)
				break;
		}
		ret.append(s,b,i-b);
	}
	return ret;
}

void main()
{
	string s="The quick brown fox jumps\n over the lazy dog.\t";
	cout<<strFilter8(s)<<endl;

	string ret;
	strFilter5(ret,s);
	cout<<ret<<endl;

	const size_t n = 88;
	char* src = "The quick brown fox jumps\n over the lazy dog.\t";
	char dest[n];
	memset(dest,0,n);
	strFilter6(dest,src);
	cout<<dest<<endl;
    system("pause");
}
/*
The quick brown fox jumps over the lazy dog.
The quick brown fox jumps over the lazy dog.
The quick brown fox jumps over the lazy dog.
*/
