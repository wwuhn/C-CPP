#include <iostream>
using namespace std;

template<class T> void output(T a)
{cout<<a<<endl;}

void main()
{
	//��ʽʵ����
	cout<<"��ʽʵ�������"<<endl;
	output(1);      //����
	output(1.2);    //������
	cout<<"��ʽʵ�������"<<endl;
	//��ʾʵ����
	output<int>(34);        //����
	output<double>(3.1415); //������
}