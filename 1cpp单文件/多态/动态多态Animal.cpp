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

int main()
{
    Animal * anim1 = new Dog;
    Animal * anim2 = new Cat;
    Animal * anim3 = new Bird;
     
   //����ָ�루�����ã����õĽӿڣ���������ȷ��ָ�루�����ã���ָ������������ͣ����ø����Ͷ�Ӧ�Ľӿ�
    anim1->shout();
    anim2->shout();
    anim3->shout();
 
    //delete ����
    delete anim1;
	delete anim2;
	delete anim3;
	system("pause");
   return 0;
}
/*
������
����~
ߴ��!
*/