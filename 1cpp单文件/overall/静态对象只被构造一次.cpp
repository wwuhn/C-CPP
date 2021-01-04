#include<iostream.h>

class Sample 
{ 
	int x; 
public: 
	Sample(int a) 
	{ 
		x=a;
		cout<<"constructing object:x="<<x<<endl; 
	} 
}; 

void func(int n) 
{ 
	static Sample obj(n);//静态对象与静态变量一样，只构造一次
} 

void main() 
{ 
	func(1); 
	func(10); 
	cin.get();
}

