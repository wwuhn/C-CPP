#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool evenNum( int n ) //�Ƿ�Ϊż��
{ return n % 2; }

void main()
{
	int num = 6;
	vector<int> v1;
	for( int i = 0; i != 10; ++i )
		v1.push_back(i);

	vector<int>::iterator iter = find( v1.begin(), v1.end(), num ); //���ҵ���6��Ԫ��λ��
	if( iter != v1.end() )
		cout << "ƥ��Ԫ�ص�����: " << iter - v1.begin() << endl; //�ҵ�ƥ��Ԫ��λ��6

	vector<int> v2;
	v2.push_back(6);
	v2.push_back(5);
	v2.push_back(3);
	iter = find_first_of( v1.begin(), v1.end(), v2.begin(), v2.end() ); //��һ��ƥ��Ԫ����3
	if( iter != v1.end() )
		cout << "��һ��ƥ��Ԫ��������" << iter - v1.begin() << endl;

	int even_times = count_if( v1.begin(), v1.end(), evenNum ); //ν�ʺ���������ż������Ϊ5��
	cout << "ż������ ��" << even_times << endl;
	cin.get();
}
/*
ƥ��Ԫ�ص�����: 6
��һ��ƥ��Ԫ��������3
ż������ ��5
*/




































