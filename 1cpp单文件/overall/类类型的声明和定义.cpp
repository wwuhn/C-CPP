#include <iostream>
using namespace std;

class AGE;       // ������
class STUDENT    // �ඨ��
{
public:
    char name[20];
    int num;
    AGE* birthday; //ֻʹ��ָ���������ʽ
    float score;
};

class AGE    // �ඨ��
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
