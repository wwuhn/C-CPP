#include <iostream>
using namespace std;

class AGE    // �ඨ��
{
public:
    int year;
    int month;
    int day;
};

class STUDENT    // �ඨ��
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
