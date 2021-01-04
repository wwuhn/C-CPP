#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include <sstream>

template<class T>
void to_string(string & result,const T& t)
{
	ostringstream oss;	//创建一个流
	oss<<t;				//把值传递如流中
	result=oss.str();	//获取转换后的字符转并将其写入result
}

int main()
{
	string str;
	to_string(str,10.5);//double到string
	cout<<str<<endl;
	to_string(str,123);//int到string
	cout<<str<<endl;
	to_string(str,true);//bool到string
	cout<<str<<endl;
	system("pause");
	return 0;
	
}
