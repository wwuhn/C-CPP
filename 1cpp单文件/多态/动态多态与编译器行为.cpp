#include<iostream>
using namespace std;

class Animal
{
public :
	virtual void shout() = 0;
};

class Dog :public Animal
{
public:
	virtual void shout(){ cout << "汪汪！"<<endl; }
};

class Cat :public Animal
{
public:
	virtual void shout(){ cout << "喵喵~"<<endl; }
};

class Bird : public Animal
{
public:
	virtual void shout(){ cout << "叽喳!"<<endl; }
};

// ① 编译器会为有virtual函数成员的类建立一个虚函数表
int main()
{
	Animal * animal;
	Dog dog;
	animal = &dog;
	animal->shout();
	Cat cat;

	// ② 编译器会为每个新建对象添加一函数指针，指向虚函数表
	animal = &cat;
	animal->shout();//animal代表this指针，shout是虚函数
	//*(animal->vanimal[1])(animal);
	Animal * anim3 = new Bird;
	
	
	anim3->shout();
	// ③ 编译器会改写对象调用成员函数代码，改写成指针调用的形式
	delete anim3;
	system("pause");
	return 0;
}