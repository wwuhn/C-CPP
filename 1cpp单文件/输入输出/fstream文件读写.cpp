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
	//C++�ļ��Ķ�д�Ϳ���̨��дһ��������������ȡ�������>>�����ļ������ݣ�
	//Ҳ�������������������<<��������д���ļ���Ҳ�������ļ�����������Ա������д�ļ���
	//��get������put�����ȡ�

	for (i = 1; i <= 10; ++i) 
		out << i << ' '; 
	out.close();
	
	in.open("file.txt"); 
	if (!in) 
	{cerr << "open file error\n"; return 1;}
	// �ж��ļ�����
	// >>��������ͨ���ж�����������ֵ�Ƿ�Ϊ0��
	// get�����ж϶����ַ��Ƿ���EOF��
	// ������ʽ����ͨ����Ա����eof��eof��������Ҫ����������һ������ֵ��
	// �������������ļ�����ʱ���ú�������1�����򷵻�0��

	while (in >> i) 
		cout << i << ' ';  
	in.close();
	
	return 0;
} 
