#include <iostream>
using namespace std;

class point;
class anotherPoint //anotherPoint�ඨ��
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
	//  explicit //����ڹ��캯��ǰ����explicit, �Ͳ����� point pt1 = 5������ʽת����
    point(int x = 0, int y = 0)
    {
        xPos = x;
        yPos = y;
    }

    point(anotherPoint aP)      //���캯��������ΪanotherPoint�����
    {
        xPos = aP.x;            //����point����anotherPoint�����Ԫ��,
        yPos = aP.y;            //���������Է���anotherPoint��˽�б���x��y
    }
	
    void print()
    {
        cout << "( " << xPos << " , " << yPos << " )" << endl;
    }
};

int main()
{
    //1. ��int��������5ת����point����
    point p1;           //����point�����p1�����ô�ȱʡ�����Ĺ��캯������x��0��y��0
    cout << 5 << " ת���� ";
    p1 = 5;             //�ȼ���p1��point(5,0);
    p1.print();         //�����p1����Ϣ
	
    //2. ��double���ͱ���dXת����point����
    double dX = 1.2;    //����һ��double����dX
    cout << dX << " ת���� ";
    p1 = dX;            //�ȼ���p1=point(int(dX),0)
    p1.print();         //�����p1����Ϣ
	
    //3. ��anotherPoint����ת����point����
    anotherPoint p2(12.34, 56.78);  //����anotherPoint��Ķ���p2
    p2.print();
    cout << " ת���� ";
    p1 = p2;            //�ȼ���p1=point(p2);
    p1.print();         //�����p1����Ϣ
	
    //4. ������point���캯��ǰ����explicit����ֹ����ת�������
    system("pause");
    return 0;
}
/*
5 ת���� ( 5 , 0 )
1.2 ת���� ( 1 , 0 )
( 12.34 , 56.78 ) ת���� ( 12 , 56 )
*/