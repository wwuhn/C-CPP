#include <ctime>
#include <iostream>
using namespace std;

int const SIZE_A = 1024*1024;

struct BigData
{
	BigData():ptr(new char[SIZE_A]){}

	BigData(BigData const& other):ptr(new char[SIZE_A]) // �������
	{
		copy(other.ptr,other.ptr+SIZE_A,ptr);
	}

	BigData(BigData && other):ptr(other.ptr) // �ƶ�����
	{
		other.ptr=NULL;
	}

	~BigData()
	{
		delete[] ptr;
	}

	char* ptr;
};

BigData GetData()
{
	BigData data;
	return data;
}

BigData* GetDataPtr()				// ���ض����ڴ�
{
	BigData* data = new BigData();
	return data;
}
int main()
{
	clock_t beg=clock();
	for(int i=0; i<10000; ++i)
	{
		#if 0
		BigData data = GetData();
		#else
		BigData* data = GetDataPtr();
		//
		delete data;			// �ͷź������صĶ����ڴ�
		#endif
	}

	cout<<(clock()-beg)*1000/CLOCKS_PER_SEC<<endl;
    system("pause");
	return 0;
}

