#include <iostream>
using namespace std;

int main()
{ 
	
	cin.get();cin.get()
    return 0;
}

/*
1 在C++下，若要使用C中已有库中的函数，文件包含方式为前面加一个c，同时去掉.h后缀，
如#include <cstdio>，同时必须加上using namaspace;
对于C++特有的库，直接用去掉.h后缀的文件包含，并加上using namaspace;
2 C或C++的控制台程序的输入函数，空格或回车都表示一个值输入的结束；
3 getchar();getchar(); 控制台的字符无法复制；
4 VC6在{{}{}}结构中，内部的{}不能使用相同的局部变量；
*/