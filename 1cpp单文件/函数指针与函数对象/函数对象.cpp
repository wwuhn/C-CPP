#include <iostream>
using namespace std;
template <typename T>

class mymax
{
public:
	T operator()(T a, T b)	// ���ء�()�����������������������ʵ�־��幦��
	{
		return a>b?a:b;
	}
};	
						    // ���ء�()��������������Ϊһ����������
template <typename T>		// ���ú��������庯��ģ�壬�������Ϊ����ָ����Ϊ�ص�����
T compare(T a, T b, mymax<T>& op)
{
	return op(a,b);			// ���ô��ݽ����ĺ���������о���ıȽϲ���
}

void main()
{
	mymax<int> intmax;		// ����һ��int���͵ĺ�������
	int nMax = intmax(3,4);	//ֱ��ʹ�ú�������
	// ��������Ϊ��int nMax = intmax.operator()(3,4);
	cout<<nMax<<endl;
	nMax = compare(5,6,intmax);//������������Ϊ�������ݸ���������
	cout<<nMax<<endl;
	system("pause");
}
/*
4
6
*/