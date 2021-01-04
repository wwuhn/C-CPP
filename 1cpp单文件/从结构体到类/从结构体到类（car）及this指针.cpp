
#include <iostream>
using namespace std;

struct CCar
{
	int price;
};

void SetPrice(struct CCar* pthis,int p)
{
    pthis->price = p; 
} 

class Car
{
public: 
	int price; 
	void SetPrice (int p); 
}; 

void Car::SetPrice (int p) 
{ 
	price = p; //也可以显示地写出来：this->price = p;
} 

void main()
{ 
	struct CCar ccar; 
	SetPrice( &ccar, 20000);
	cout<<ccar.price<<endl;;

	Car car; 
	car.SetPrice(20000); 
	cout<<car.price<<endl;
    while(1);
}
