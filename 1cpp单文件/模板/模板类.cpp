#include <iostream>
using namespace std;

// ����ṹ��Student
struct Student
{
	int   id;         // ѧ��
	float average;    // ƽ����
};

// ��ģ�壬ʵ�ֶ��������͵����ݽ��д�ȡ
template <class T>
class Store
{
public:
	Store(void);        // Ĭ����ʽ�����βΣ��Ĺ��캯��
	T GetElem(void);    // ��ȡ����
	void PutElem(T x);  // ��������
private:
	T item;             // item��������������͵�����
	int haveValue;      // ��ʶitem�Ƿ񱻴�������
};
// �����ǳ�Ա������ʵ�֣�ע�⣬��ģ��ĳ�Ա�������Ǻ���ģ��
// ���캯����ʵ��
template <class T>
Store<T>::Store(void):haveValue(0)
{
}
// ��ȡ���ݵĺ�����ʵ��
template <class T>
T Store<T>::GetElem(void)
{
	// ��itemû�д������ݣ�����ֹ����
	if (haveValue == 0)
	{
		cout << "itemû�д�������!" << endl;
		exit(1);
	}
	return item;
}

// �������ݵĺ�����ʵ��
template <class T>
void Store<T>::PutElem(T x)
{
	haveValue = 1;          // ������Ϊ1����ʾitem�Ѿ���������
	item = x;                // ��x��ֵ����item
}

int main()
{
	// ����Student�ṹ�����ͱ�����������ֵ
	Student g = { 103, 93 };
	// ��������Store��Ķ������ݳ�ԱitemΪint����
	Store<int> S1, S2;
	// ����Store�����S3�����ݳ�ԱitemΪStudent�ṹ������
	Store<Student> S3;
	
	
	S1.PutElem(7);    // �����S1�д�����ֵ7
	S2.PutElem(-1);   // �����S2�д�����ֵ-1
	// ���S1��S2�����ݳ�Ա��ֵ
	cout << S1.GetElem() << "  " << S2.GetElem() << endl;
	
	S3.PutElem(g);    // �����S3�д���Student�ṹ�����ͱ���g
	// �������S3�����ݳ�Ա
	cout << "The student id is " << S3.GetElem().id << endl;
	system("pause");
	return 0;
}
/*
7  -1
The student id is 103
*/

