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
			cout << "索引超过最大值" <<endl;
			// 返回第一个元素
			return arr[0];
		}
		if( i < 0 )
		{
			cout << "索引小于0" <<endl;
			// 返回第一个元素
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
	cout << "arr[-1] 的值为 : " << arr[-1] <<endl;

	cout << "arr[2] 的值为 : " << arr[2] <<endl;
	cout << "arr[9] 的值为 : " << arr[9]<<endl;
	cout << "arr[10] 的值为 : " << arr[10]<<endl;
	cout<<before<<" "<<after<<endl;
	system("pause");
	return 0;
}
/*
索引小于0
arr[-1] 的值为 : 0
arr[2] 的值为 : 2
arr[9] 的值为 : 9
索引超过最大值
arr[10] 的值为 : 0
111 999
*/