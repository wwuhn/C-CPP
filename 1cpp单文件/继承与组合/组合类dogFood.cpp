#include<iostream>
using namespace std;

class Food
{
public:
	Food()
	{
		cout<<"����Ĭ�Ϲ��캯��"<<endl;
	}
	Food(Food& other)
	{
		cout<<"���ÿ������캯��"<<endl;
	}
	Food& operator=(Food& other)
	{
		cout<<"���ø�ֵ������"<<endl;
		return other;
	}
};

class Dog
{
	Food m_food;
public:
	//Dog(Food& food):m_food(food){} //����Ĭ�Ϲ��캯��,ʹ�ó�ʼ���б����ٵ��ø�ֵ��������
	//�����������ͣ�ʹ�ó�ʼ���б��빹�캯����ʼ����һ����
	Dog(Food& food)//����Ĭ�Ϲ��캯��
	{
		m_food = food;//���ø�ֵ������
	}
};

void main()
{
	Food f;
	Dog d(f);

    system("pause");
}
/*
����Ĭ�Ϲ��캯��
����Ĭ�Ϲ��캯��
���ø�ֵ������
*/