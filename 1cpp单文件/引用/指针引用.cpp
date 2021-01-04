#if(0) //二级指针，也就是指针的指针，用于修改指针指向的一个指针(如果是一级指针，修改的是指向的内容)
#include <iostream>
using namespace std;

void GetMemory2(char **p, int num)  // 指针传址，地址指向一个指针， 
{
    *p = (char *)malloc(sizeof(char) * num);
}

void Test(void)	
{	
    char *str = NULL;	
    GetMemory2(&str, 100);	        // 注意参数是&str，而不是str
    strcpy(str, "hello");	
    cout<< str << endl;	
    free(str);	
}

void main()
{
    Test();
    system("pause");
}
#endif


#if(0) //指针引用，也就是指针的引用，用于修改引用指向的一个指针(如果是引用，修改的是引用指向的内容)
#include <iostream>
using namespace std;

void GetMemory2(char *&p, int num) 		 	// 引用传址，地址指向一个指针，  
{
    p = (char *)malloc(sizeof(char) * num); // 注意参数是p，而不是*p
}

void Test(void)	
{	
    char *str = NULL;	
    GetMemory2(str, 100);	// 注意参数是str，而不是&str
    strcpy(str, "hello");	
    cout<< str << endl;	
    free(str);	
}

void main()
{
    Test();
    system("pause");
}
#endif

#if(1) //以上操作如果不使用指针的指针或指针引用，也可以返回一个指针来达到同样的目的
#include <iostream>
using namespace std;

char *GetMemory3(int num)
{
    char *p = (char *)malloc(sizeof(char) * num); 
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory3(100); 
    strcpy(str, "hello"); 
    cout<< str << endl; 
    free(str);
}

void main()
{
    Test();
    system("pause");
}
#endif