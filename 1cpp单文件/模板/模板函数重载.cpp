#include <iostream>
using namespace std;

template<class T> T add(T a, T b)//ģ��ӷ�����
{
	return a+b;
}
template<class T> T add(T a, T b, T c)//����ģ��ӷ�����
{
	return a+b+c;
}
void main()
{
	cout<<add(1,2)<<endl;//���ͼӷ�
	cout<<add(1.2,3.4,4.5)<<endl;//����ӷ�
}