#include <stdio.h>

int& func(int& p)   //��Ϊp�Ǵ��������������������ã����Ե�func����ʱ��Ȼ���ڣ�����
{
    p++;
    return p;       //OK: ������Ϊ����ֵ
}

int main()
{
    int i=10;
    int& p=i;

    printf("%d\n", func(p));
    return 0;
}

#if 0
#include <stdio.h>

int& func(int* p)   //��Ϊp�Ǵ��������������������ã����Ե�func����ʱ��Ȼ���ڣ�����
{
    (*p)++;
    return *p;      //OK: ������Ϊ����ֵ
}

int main()
{
    int i=10;
    int& p=i;

    printf("%d\n", func(&i));
    return 0;
}
#endif