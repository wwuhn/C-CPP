#include <iostream>
using namespace std;

class point;
class anotherPoint //anotherPoint类定义
{
private:
    double x;
    double y;
	
public:
    anotherPoint(double xx = 1, double yy = 1)
    {
        x = xx;
        y = yy;
    }
    void print()
    {
        cout << "( " << x << " , " << y << " )";
    }
    friend class point;
};

class point
{
private:
    int xPos;
    int yPos;
	
public:
	//  explicit //如果在构造函数前加上explicit, 就不允许 point pt1 = 5这种隐式转换了
    point(int x = 0, int y = 0)
    {
        xPos = x;
        yPos = y;
    }

    point(anotherPoint aP)      //构造函数，参数为anotherPoint类对象
    {
        xPos = aP.x;            //由于point类是anotherPoint类的友元类,
        yPos = aP.y;            //因此这里可以访问anotherPoint的私有变量x和y
    }
	
    void print()
    {
        cout << "( " << xPos << " , " << yPos << " )" << endl;
    }
};

int main()
{
    //1. 将int类型数字5转换成point类型
    point p1;           //创建point类对象p1，采用带缺省参数的构造函数，即x＝0、y＝0
    cout << 5 << " 转换成 ";
    p1 = 5;             //等价于p1＝point(5,0);
    p1.print();         //输出点p1的信息
	
    //2. 将double类型变量dX转换成point类型
    double dX = 1.2;    //声明一个double变量dX
    cout << dX << " 转换成 ";
    p1 = dX;            //等价于p1=point(int(dX),0)
    p1.print();         //输出点p1的信息
	
    //3. 将anotherPoint类型转换成point类型
    anotherPoint p2(12.34, 56.78);  //创建anotherPoint类的对象p2
    p2.print();
    cout << " 转换成 ";
    p1 = p2;            //等价于p1=point(p2);
    p1.print();         //输出点p1的信息
	
    //4. 测试在point构造函数前加上explicit以阻止隐性转换的情况
    system("pause");
    return 0;
}
/*
5 转换成 ( 5 , 0 )
1.2 转换成 ( 1 , 0 )
( 12.34 , 56.78 ) 转换成 ( 12 , 56 )
*/