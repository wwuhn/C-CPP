#include <iostream>
#include <fstream>
using namespace std;
int main()
{ 
	ofstream out("file.txt");
	ifstream in; 
	int i;
	
	if (!out) 
	{cerr << "create file error\n"; return 1;}
	//C++文件的读写和控制台读写一样，可以用流提取运算符“>>”从文件读数据，
	//也可以用流插入运算符”<<”将数据写入文件，也可以用文件流的其他成员函数读写文件，
	//如get函数，put函数等。

	for (i = 1; i <= 10; ++i) 
		out << i << ' '; 
	out.close();
	
	in.open("file.txt"); 
	if (!in) 
	{cerr << "open file error\n"; return 1;}
	// 判断文件结束
	// >>读：可以通过判断输入流对象值是否为0。
	// get读：判断读入字符是否是EOF。
	// 其他方式读：通过成员函数eof。eof函数不需要参数，返回一个整型值。
	// 当读操作遇到文件结束时，该函数返回1，否则返回0。

	while (in >> i) 
		cout << i << ' ';  
	in.close();
	
	return 0;
} 
