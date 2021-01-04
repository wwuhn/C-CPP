//DetectPass.h
#include <string>
#include <iostream>
using namespace std;

enum PassStatus {pass,failed,reject};	//ö�����Ͷ�������״̬

class DetectPass
{
public:
	DetectPass();
	~DetectPass();
	PassStatus operator() (string passstr); //���Ų���������
protected:
	int numOfRun; 		//�ó�Ա���ݼ�¼��������Ĵ���(����״̬)
	string getpass();	//��ģ�⣩ͨ�����ݿ��ȡ����
};

//DetectPass.cpp
//#include "DetectPass.h"
DetectPass::DetectPass()
{
	cout <<"���캯������..." <<endl;
	numOfRun=0;
}

DetectPass::~DetectPass()
{
	cout <<"������������..." <<endl;
}

PassStatus DetectPass::operator() (string passstr)
{
	cout <<"���ǵ�" <<++numOfRun <<"���������룬";//״̬����
	if (numOfRun<=3)
	{
		if (passstr.compare(getpass())==0)//passstr��string���ͣ���compare()��Ա����
		{
			cout <<"������ȷ��" <<endl <<"��ӭ����ϵͳ��" <<endl;
			return pass;
		}
		else
		{
			cout <<"�������" <<endl;
			return failed;
		}
	}
	else
	{
		cout <<"���Ѿ�����������Σ��쳣�˳���" <<endl;
		return reject;
	}
}
string DetectPass::getpass()
{
	return string("123456");
}

//main.cpp
//#include "DetectPass.h"
//#include <string>
//#include <iostream>
using namespace std;
DetectPass password; 		//����һ����password����ͬ���Ķ���
int main()
{
	string input;
	do
	{
		cout <<"���������룺";
		cin >>input;
	}while(password(input)==failed); //���������ǵ���password����
	while(1);
	return 0;	
}
/*
���캯������...
���������룺123
���ǵ�1���������룬�������
���������룺456
���ǵ�2���������룬�������
���������룺123456
���ǵ�3���������룬������ȷ��
��ӭ����ϵͳ��
*/