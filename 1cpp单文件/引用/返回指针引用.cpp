#include <stdio.h>

int g = 0;
int *pg = &g;

int &func(int &i)   // ������Ϊ�����ͷ���ֵ
{
	i = - 1;
	return g ;
}

int* &func(int* &i) // ָ��������Ϊ�����ͷ���ֵ
{
	*i = - 11;
	return i ; 
}

void main(void)
{
	int j=10;
	func(j)=100;
	printf("%d\n",j);  // -1

	printf("%d\n",g);  // 100
	int* p = func(pg);
	printf("%d\n",g);  // -11
	printf("%d\n",*p); // -11
    
	*func(pg)=22;
	printf("%d\n",g);  // 22
	getchar();
}