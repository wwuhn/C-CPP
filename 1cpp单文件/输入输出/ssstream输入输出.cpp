#include <iostream>
#include <string>
using namespace std;
#include <sstream>

int main()
{	
	ostringstream oss; // output memory for writing to a string
	oss<<"{temperature,"<<scientific<<123.4567890 << "}"; //设置各类型数据到输出流oss
	cout<<oss.str()<<endl;  // 输出流数据输出
	
     string src="If you are a boy!"; 
     istringstream iss(src); // 设置数据到输入流
     string dst; 
     while(iss>>dst)         //输入流输入
     { 
         cout<<dst<<endl; 
     } 
	system("pause");
	return 0;
 
}
/*
{temperature,1.234568e+002}
If
you
are
a
boy!
*/