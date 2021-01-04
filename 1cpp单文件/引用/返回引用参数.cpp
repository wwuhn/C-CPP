#include <stdio.h>

int& func(int& p)   //因为p是从主调函数传过来的引用，所以当func结束时依然存在，所以
{
    p++;
    return p;       //OK: 可以做为返回值
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

int& func(int* p)   //因为p是从主调函数传过来的引用，所以当func结束时依然存在，所以
{
    (*p)++;
    return *p;      //OK: 可以做为返回值
}

int main()
{
    int i=10;
    int& p=i;

    printf("%d\n", func(&i));
    return 0;
}
#endif