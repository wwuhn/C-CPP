#include <iostream>
using namespace std;

const int SIZE = 10;

class Arrs
{
private:
	int arr[SIZE];
public:

	Arrs()
	{
		register int i;
		for(i = 0; i < SIZE; i++)
		{
			arr[i] = i;
		}
	}

	int& operator[](int i)
	{
		if( i >= SIZE )
		{
			cout << "�����������ֵ" <<endl;
			// ���ص�һ��Ԫ��
			return arr[0];
		}
		if( i < 0 )
		{
			cout << "����С��0" <<endl;
			// ���ص�һ��Ԫ��
			return arr[0];
		}
		return arr[i];
	}
};

int main()
{
	int before = 111;
	Arrs arr;
	int after = 999;
	cout << "arr[-1] ��ֵΪ : " << arr[-1] <<endl;

	cout << "arr[2] ��ֵΪ : " << arr[2] <<endl;
	cout << "arr[9] ��ֵΪ : " << arr[9]<<endl;
	cout << "arr[10] ��ֵΪ : " << arr[10]<<endl;
	cout<<before<<" "<<after<<endl;
	system("pause");
	return 0;
}
/*
����С��0
arr[-1] ��ֵΪ : 0
arr[2] ��ֵΪ : 2
arr[9] ��ֵΪ : 9
�����������ֵ
arr[10] ��ֵΪ : 0
111 999
*/