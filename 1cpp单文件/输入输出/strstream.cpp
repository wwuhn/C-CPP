//ostrstream类流  
#include<iostream>  
#include<strstrea.h>  
#include<string.h>  

void main()  
{  
    const int LENGTH=80;  
    char buffer[LENGTH];  
    double dnum=-1234.512356;  
    ostrstream sout(buffer,sizeof(buffer));  
    sout.setf(ios::fixed|ios::showpoint|ios::showpos);  
    sout<<dnum<<'\0';  
    cout<<buffer<<endl;  //-1234.512356
	//ostrstream流可以实现将一个二进制数转换成串的字符存入在字符数组对象中。
    char *p=sout.str(); 
    cout<<p<<endl;   //-1234.512356
    cout<<sout.pcount()<<endl;  //13

//istrstream类流  
    const int LEN=80;  
    char buf[LEN]="65 43.21";  
    char buf2[LEN]="543.21";  
    double d;  
    int i;  
	//istrstream流可以实现将一个字符串的数字字符转换成二进制形式存入在某种类型的对象中。

	//istrstream流为流对象提供了两种构造函数，它们的原型分别是： 
	//istrstream ::istrstream (char *s) 
	//istrstream ::istrstream (char *s,int n) 
	istrstream sin(buf);  
    sin>>i>>d;  
    cout<<i<<" "<<d<<endl;  //65 43.21
    istrstream sin2(buf2,3);  
    sin2>>d;  
    cout<<d<<endl;  //543
	system("pause");
} 
