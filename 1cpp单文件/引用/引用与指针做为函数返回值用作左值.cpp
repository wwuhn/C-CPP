#include <iostream>
using namespace std;

int& g2(void)
{
    static int a = 10;
    a++;
    printf("a:%d \n", a);
    return a; 
}

int main(void)
{
    g2() = 100; //函数返回值是一个引用，当左值。
    g2();
	system("pause");
    return 0;
}
/*
a:11
a:101
*/


#if 0
#include <iostream>
using namespace std;
int& g2(void)
{
  static int a = 10;
  a++;
  printf("a:%d \n", a);
  return a; 
}
int main(void)
{
  g2() = 100; //函数返回值是一个引用，当左值。
  g2();
	system("pause");
  return 0;
}
/*
a:11
a:101
*/
#endif