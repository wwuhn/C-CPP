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

int main()
{
    Animal * anim1 = new Dog;
    Animal * anim2 = new Cat;
    Animal * anim3 = new Bird;
     
   //藉由指针（或引用）调用的接口，在运行期确定指针（或引用）所指对象的真正类型，调用该类型对应的接口
    anim1->shout();
    anim2->shout();
    anim3->shout();
 
    //delete 对象
    delete anim1;
	delete anim2;
	delete anim3;
	system("pause");
   return 0;
}
/*
汪汪！
喵喵~
叽喳!
*/