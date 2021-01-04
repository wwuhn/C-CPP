#include <iostream>
using namespace std;

struct Animal{
	int m_age;
	void speak(){
		cout<< "Animal speaking!" <<endl;
	}
	virtual void run(){
		cout<< "Animal running!" <<endl;
	}
	void eat(){
		cout<< "Animal eating!" <<endl;
	}
};

struct Dog:Animal{
	void speak(){
		cout<< "Dog speaking!" <<endl;
	}
	void run(){
		cout<< "Dog running!" <<endl;
	}
	void eat(){
		cout<< "Dog eating!" <<endl;
	}
};

struct Cat:Animal{
	int life;
	void speak(){
		cout<< "Cat speaking!" <<endl;
	}
	void run(){
		cout<< "Cat running!" <<endl;
	}
	void eat(){
		cout<< "Cat eating!" <<endl;
	}
};

struct Pig:Animal{
	void speak(){
		cout<< "Pig speaking!" <<endl;
	}
	void run(){
		cout<< "Pig running!" <<endl;
	}
	void eat(){
		cout<< "Pig eating!" <<endl;
	}
};

void liu(Animal* p){
	p->speak();
	p->run();
}

int main()
{
	// 父类指针指向子类对象是安全的，因为父类对象成员所占内存空间<=子类对象所占内存空间
	Animal* pa = new Cat();
	pa->m_age = 3;

	Cat* pc = (Cat*)new Animal(); //没有强制类型转换，编译器不允许
	pc->m_age = 4; // 安全，Animal对象包含有此成员
	pc->life  = 9; // 不安全，Animal对象不包含此成员

	liu(new Dog());
	liu(new Cat());
	
	Animal* p = new Pig();
	p->speak(); // no virtual
	p->run();	// virtual

    system("pause");
	return 0;
}
/*Output:
Animal speaking!
Dog running!
Animal speaking!
Cat running!
Animal speaking!
Pig running!
*/
