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
	// ����ָ��ָ����������ǰ�ȫ�ģ���Ϊ��������Ա��ռ�ڴ�ռ�<=���������ռ�ڴ�ռ�
	Animal* pa = new Cat();
	pa->m_age = 3;

	Cat* pc = (Cat*)new Animal(); //û��ǿ������ת����������������
	pc->m_age = 4; // ��ȫ��Animal��������д˳�Ա
	pc->life  = 9; // ����ȫ��Animal���󲻰����˳�Ա

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
