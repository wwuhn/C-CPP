#include <iostream>
#include <string>
using namespace std;

class BaseMember
{
public:
	BaseMember(){cout<<"BaseMember constructor is called\n";}
};

class Base
{
public:
//基类构造函数，初始化成员变量
         Base(int n, string na, char se):num(n),name(na),sex(se)
		 {cout<<"Base Constructor is called"<<endl;}

         ~Base(){cout<<"~Base"<<endl;}

         void display1(){cout<<num<<'\t'<<name<<'\t'<<sex<<'\t'; }
protected:
         int num;
         string name;
         char sex;
		 BaseMember baseMember;
};
 
class Derived:public Base
{
public:
//派生类调用基类构造函数
         Derived(int n, string na, char se, int n_m, string na_m, char se_m, int a, string add):Base(n,na,se),monitor(n_m,na_m,se_m)
         {age = a; addr = add;cout<<"Derived Constructor is called"<<endl;}

         ~Derived(){cout<<"~Derived"<<endl;}

         void display2(){display1();cout<<age<<'\t'<<addr<<endl; }

         void showmonitor()
         {cout<<"Monitor is:"<<endl;
                   monitor.display1();
                   cout<<endl;}
private:
         int age;
         string addr;
         Base monitor;//包含子对象
};

int main()
{
         Derived s(200, "ace", 'M', 11, "HH", 'M', 26, "Shanghai");
         s.display2();
         s.showmonitor();
		 cin.ignore();
         return 0;
}
/*
BaseMember constructor is called
Base Constructor is called
BaseMember constructor is called
Base Constructor is called
Derived Constructor is called
200     ace     M       26      Shanghai
Monitor is:
11      HH      M
*/