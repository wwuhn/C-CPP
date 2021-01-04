#include <iostream>
using namespace std;

const baseScore = 75;
const arrSize = 5;

// 1 函数指针实现回调
bool CmpGf(int base,int num)	// 比较函数
{
	return num>=base; // 也可以返回整数值，设置各种比较情况
}

typedef bool (* pf_t)(int,int); // 函数指针

int count(int grade[],pf_t pf) // 用函数指针统计大于某一成绩的人数
{
	int sum = 0;
	for(int i=0; i<arrSize; i++)
	{
		if(pf(baseScore,grade[i]))
			sum++;
	}
	return sum;
}

// 2 函数对象实现回调
struct CmpG{ // 比较对象，以某一数字为基准
	int base;
	bool operator()(int score) const
	{ return (score>=base);} // 也可以返回整数值，设置各种比较情况
};

int count(int grade[],CmpG cmp) // 用函数对象统计大于某一成绩的人数
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
