#include <iostream>

class Tricycle					//声明类
{
private:
    int speed;					//数据成员，成员函数或方法的操作对象
public:
    Tricycle(int initialAge);
    ~Tricycle();
	//↓ 两个特殊的成员变量，称为存取器（accessor），用于获取和设置私有成员变量值
    int getSpeed();				//成员函数，对数据成员的操作：这里是获取私有成员变量值
    void setSpeed(int speed);	//成员函数，对数据成员的操作：这里是设置私有成员变量值
    void pedal();				//成员函数，对数据成员的操作；
    void brake();				//成员函数，对数据成员的操作；
};
 
// constructor for the object
Tricycle::Tricycle(int initialSpeed)  //特殊成员函数，称构造函数，用于初始化对象的成员数据
{
    setSpeed(initialSpeed);
}
 
// destructor for the object
Tricycle::~Tricycle()			//特殊成员函数，称析构函数，用于释放分配给对象的内存
{
								// do nothing
}

// get the trike's speed
int Tricycle::getSpeed()
{
    return speed;
}
  
// set the trike's speed
void Tricycle::setSpeed(int newSpeed)
{
    if (newSpeed >= 0)
    {
        //speed = newSpeed;
		this->speed = newSpeed;	//也可以显式使用this指针
    }
}

// pedal the trike
void Tricycle::pedal()
{
    setSpeed(speed + 1);
    std::cout << "\nPedaling; tricycle speed " << getSpeed() << " mph\n";
}

// apply the brake on the trike
void Tricycle::brake()
{
    setSpeed(speed - 1);
    std::cout << "\nBraking; tricycle speed " << getSpeed() << " mph\n";
}

// create a trike and ride it
int main()
{
    Tricycle wichita(5);					//在栈中创建（实例化）一个对象
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();

	Tricycle *pWichita = new Tricycle(15);	//在堆中创建（实例化）一个对象
	(*pWichita).pedal();					//通过解引用和句点运算符访问对象成员
	pWichita->pedal();						//使用指向运算符（->）访问对象成员
	delete pWichita;
	system("pause");
    return 0;
}