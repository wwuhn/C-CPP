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
	static Sample obj(n);//��̬�����뾲̬����һ����ֻ����һ��
} 

void main() 
{ 
	func(1); 
	func(10); 
	cin.get();
}

