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
	virtual void shout(){ cout << "������"<<endl; }
};

class Cat :public Animal
{
public:
	virtual void shout(){ cout << "����~"<<endl; }
};

class Bird : public Animal
{
public:
	virtual void shout(){ cout << "ߴ��!"<<endl; }
};

// �� ��������Ϊ��virtual������Ա���ཨ��һ���麯����
int main()
{
	Animal * animal;
	Dog dog;
	animal = &dog;
	animal->shout();
	Cat cat;

	// �� ��������Ϊÿ���½��������һ����ָ�룬ָ���麯����
	animal = &cat;
	animal->shout();//animal����thisָ�룬shout���麯��
	//*(animal->vanimal[1])(animal);
	Animal * anim3 = new Bird;
	
	
	anim3->shout();
	// �� ���������д������ó�Ա�������룬��д��ָ����õ���ʽ
	delete anim3;
	system("pause");
	return 0;
}