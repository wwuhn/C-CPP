//ostrstream����  
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
	//ostrstream������ʵ�ֽ�һ����������ת���ɴ����ַ��������ַ���������С�
    char *p=sout.str(); 
    cout<<p<<endl;   //-1234.512356
    cout<<sout.pcount()<<endl;  //13

//istrstream����  
    const int LEN=80;  
    char buf[LEN]="65 43.21";  
    char buf2[LEN]="543.21";  
    double d;  
    int i;  
	//istrstream������ʵ�ֽ�һ���ַ����������ַ�ת���ɶ�������ʽ������ĳ�����͵Ķ����С�

	//istrstream��Ϊ�������ṩ�����ֹ��캯�������ǵ�ԭ�ͷֱ��ǣ� 
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
