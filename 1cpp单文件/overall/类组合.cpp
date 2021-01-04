#include <iostream>
using namespace std;

class AGE    // 类定义
{
public:
    int year;
    int month;
    int day;
};

class STUDENT    // 类定义
{
public:
    char name[20];
    int num;
    AGE birthday; 
    float score;
};

void main()
{
	STUDENT stu;
	stu.birthday.year = 1988;
	cout<<stu.birthday.year<<endl;
    system("pause");
}
