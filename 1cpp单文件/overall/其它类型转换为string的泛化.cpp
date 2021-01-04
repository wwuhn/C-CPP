#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include <sstream>

template<class T>
void to_string(string & result,const T& t)
{
	ostringstream oss;	//����һ����
	oss<<t;				//��ֵ����������
	result=oss.str();	//��ȡת������ַ�ת������д��result
}

int main()
{
	string str;
	to_string(str,10.5);//double��string
	cout<<str<<endl;
	to_string(str,123);//int��string
	cout<<str<<endl;
	to_string(str,true);//bool��string
	cout<<str<<endl;
	system("pause");
	return 0;
	
}
