#include <iostream>
#include <string>
using namespace std;
#include <sstream>

int main()
{	
	ostringstream oss; // output memory for writing to a string
	oss<<"{temperature,"<<scientific<<123.4567890 << "}"; //���ø��������ݵ������oss
	cout<<oss.str()<<endl;  // ������������
	
     string src="If you are a boy!"; 
     istringstream iss(src); // �������ݵ�������
     string dst; 
     while(iss>>dst)         //����������
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