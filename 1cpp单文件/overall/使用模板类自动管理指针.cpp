#include <iostream>
using namespace std;

template <class T>
class ptr
{
private:
	T *ip;//ָ��
    int n;
public:
	ptr(int n);
	~ptr();
};

template <class T>
ptr<T>::ptr(int n)
{
    this->n = n;
	ip = new T[n];//��ʼ��
	cout<<"����ָ������๹�캯��"<<endl;
}

template <class T>
ptr<T>::~ptr()
{
	delete [] ip;//�ͷ�
    n=0;
	cout<<"ָ���������������������"<<endl;
}

void main()
{

	{
		ptr<int> p(10);//�Զ���ָ�������
	}//�����������Զ��������ͷ�ָ��
	system("pause");
}
/*
����ָ������๹�캯��
ָ���������������������
*/