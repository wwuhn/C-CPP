#include <iostream>
using namespace std;

class AGE;       // 类声明
class STUDENT    // 类定义
{
public:
    char name[20];
    int num;
    AGE* birthday; //只使用指针和引用形式
    float score;
};

class AGE    // 类定义
{
public:
    int year;
    int month;
    int day;
};

void main()
{
	AGE age;

	STUDENT stu;
	stu.birthday = &age;
	stu.birthday->year = 1988;
	cout<<stu.birthday->year<<endl;
    system("pause");
}
