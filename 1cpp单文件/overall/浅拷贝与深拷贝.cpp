#include<iostream>
using namespace std;

class Cstr
{
public:
	int n;
	char* str;

	Cstr(int i, char* s);
	Cstr(const Cstr& others);
	void show();
	~Cstr();
};

Cstr::Cstr(int i, char* s)
{
	n = i;
	str = new char[i];//成员中有动态内存申请
	strcpy(str,s);
}

Cstr::Cstr(const Cstr& others)
{
	n=others.n;
/*
	str = new char[n];//深拷贝
	if(str!=0)
		strcpy(str,others.str);
*/
	str = others.str; //浅拷贝
}

void Cstr::show(){cout<<str<<endl;}

Cstr::~Cstr(){ delete []str;}

void main()
{
	Cstr cstr1 (11,"string 1");
	cout<<cstr1.str<<endl;
	Cstr cstr2 = cstr1;
	cstr2.str ="other strings";
	cout<<cstr2.str<<endl;
	cout<<cstr1.str<<endl;
    system("pause");
}