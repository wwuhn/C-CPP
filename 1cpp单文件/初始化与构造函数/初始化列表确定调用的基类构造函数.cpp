#include<iostream.h>

class one
{
	int x,y;
public:
	one():x(3)
	{cout<<"���û����޲������캯��\n";} //û�в����Ĺ��캯��
	//one(int a,int b):x(a),y(b)
	//{cout<<"���û������������Ĺ��캯��";}
};

class two:public one
{
public:
	two(){} //��Ϊ�����Ѿ�����2������,����Ӧ��ָ�������ĸ�
	void disp()
	{
		cout<<"����two��disp����"<<endl;
	}
};

void main()
{
	two t;
	t.disp();
	cin.ignore();
}