#include <iostream>
using namespace std;

// 定义结构体Student
struct Student
{
	int   id;         // 学号
	float average;    // 平均分
};

// 类模板，实现对任意类型的数据进行存取
template <class T>
class Store
{
public:
	Store(void);        // 默认形式（无形参）的构造函数
	T GetElem(void);    // 获取数据
	void PutElem(T x);  // 存入数据
private:
	T item;             // item用来存放任意类型的数据
	int haveValue;      // 标识item是否被存入数据
};
// 以下是成员函数的实现，注意，类模板的成员函数都是函数模板
// 构造函数的实现
template <class T>
Store<T>::Store(void):haveValue(0)
{
}
// 获取数据的函数的实现
template <class T>
T Store<T>::GetElem(void)
{
	// 若item没有存入数据，则终止程序
	if (haveValue == 0)
	{
		cout << "item没有存入数据!" << endl;
		exit(1);
	}
	return item;
}

// 存入数据的函数的实现
template <class T>
void Store<T>::PutElem(T x)
{
	haveValue = 1;          // 将其置为1，表示item已经存入数据
	item = x;                // 将x的值存入item
}

int main()
{
	// 声明Student结构体类型变量，并赋初值
	Student g = { 103, 93 };
	// 声明两个Store类的对象，数据成员item为int类型
	Store<int> S1, S2;
	// 声明Store类对象S3，数据成员item为Student结构体类型
	Store<Student> S3;
	
	
	S1.PutElem(7);    // 向对象S1中存入数值7
	S2.PutElem(-1);   // 向对象S2中存入数值-1
	// 输出S1和S2的数据成员的值
	cout << S1.GetElem() << "  " << S2.GetElem() << endl;
	
	S3.PutElem(g);    // 向对象S3中存入Student结构体类型变量g
	// 输出对象S3的数据成员
	cout << "The student id is " << S3.GetElem().id << endl;
	system("pause");
	return 0;
}
/*
7  -1
The student id is 103
*/

