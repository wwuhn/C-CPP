#if(0) //����ָ�룬Ҳ����ָ���ָ�룬�����޸�ָ��ָ���һ��ָ��(�����һ��ָ�룬�޸ĵ���ָ�������)
#include <iostream>
using namespace std;

void GetMemory2(char **p, int num)  // ָ�봫ַ����ַָ��һ��ָ�룬 
{
    *p = (char *)malloc(sizeof(char) * num);
}

void Test(void)	
{	
    char *str = NULL;	
    GetMemory2(&str, 100);	        // ע�������&str��������str
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


#if(0) //ָ�����ã�Ҳ����ָ������ã������޸�����ָ���һ��ָ��(��������ã��޸ĵ�������ָ�������)
#include <iostream>
using namespace std;

void GetMemory2(char *&p, int num) 		 	// ���ô�ַ����ַָ��һ��ָ�룬  
{
    p = (char *)malloc(sizeof(char) * num); // ע�������p��������*p
}

void Test(void)	
{	
    char *str = NULL;	
    GetMemory2(str, 100);	// ע�������str��������&str
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

#if(1) //���ϲ��������ʹ��ָ���ָ���ָ�����ã�Ҳ���Է���һ��ָ�����ﵽͬ����Ŀ��
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