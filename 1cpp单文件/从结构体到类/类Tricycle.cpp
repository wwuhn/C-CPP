#include <iostream>

class Tricycle					//������
{
private:
    int speed;					//���ݳ�Ա����Ա�����򷽷��Ĳ�������
public:
    Tricycle(int initialAge);
    ~Tricycle();
	//�� ��������ĳ�Ա��������Ϊ��ȡ����accessor�������ڻ�ȡ������˽�г�Ա����ֵ
    int getSpeed();				//��Ա�����������ݳ�Ա�Ĳ����������ǻ�ȡ˽�г�Ա����ֵ
    void setSpeed(int speed);	//��Ա�����������ݳ�Ա�Ĳ���������������˽�г�Ա����ֵ
    void pedal();				//��Ա�����������ݳ�Ա�Ĳ�����
    void brake();				//��Ա�����������ݳ�Ա�Ĳ�����
};
 
// constructor for the object
Tricycle::Tricycle(int initialSpeed)  //�����Ա�������ƹ��캯�������ڳ�ʼ������ĳ�Ա����
{
    setSpeed(initialSpeed);
}
 
// destructor for the object
Tricycle::~Tricycle()			//�����Ա�����������������������ͷŷ����������ڴ�
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
		this->speed = newSpeed;	//Ҳ������ʽʹ��thisָ��
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
    Tricycle wichita(5);					//��ջ�д�����ʵ������һ������
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();

	Tricycle *pWichita = new Tricycle(15);	//�ڶ��д�����ʵ������һ������
	(*pWichita).pedal();					//ͨ�������ú;����������ʶ����Ա
	pWichita->pedal();						//ʹ��ָ���������->�����ʶ����Ա
	delete pWichita;
	system("pause");
    return 0;
}