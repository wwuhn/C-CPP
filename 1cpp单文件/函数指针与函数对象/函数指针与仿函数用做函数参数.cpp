#include <iostream>
using namespace std;

const baseScore = 75;
const arrSize = 5;

// 1 ����ָ��ʵ�ֻص�
bool CmpGf(int base,int num)	// �ȽϺ���
{
	return num>=base; // Ҳ���Է�������ֵ�����ø��ֱȽ����
}

typedef bool (* pf_t)(int,int); // ����ָ��

int count(int grade[],pf_t pf) // �ú���ָ��ͳ�ƴ���ĳһ�ɼ�������
{
	int sum = 0;
	for(int i=0; i<arrSize; i++)
	{
		if(pf(baseScore,grade[i]))
			sum++;
	}
	return sum;
}

// 2 ��������ʵ�ֻص�
struct CmpG{ // �Ƚ϶�����ĳһ����Ϊ��׼
	int base;
	bool operator()(int score) const
	{ return (score>=base);} // Ҳ���Է�������ֵ�����ø��ֱȽ����
};

int count(int grade[],CmpG cmp) // �ú�������ͳ�ƴ���ĳһ�ɼ�������
{
	int sum = 0;
	for(int i=0; i<arrSize; i++)
	{
		if(cmp(grade[i]))
			++sum;
	}
	return sum;
}

int main()
{
	int grade[arrSize] = {45,86,78,60,89};
	cout<<count(grade,CmpGf)<<endl;	// 3

	CmpG cmp;
	cmp.base = baseScore;
	cout<<count(grade,cmp)<<endl;	// 3

	cmp.base = 80;
	cout<<count(grade,cmp)<<endl;	// 2

    system("pause");
	return 0;
}
