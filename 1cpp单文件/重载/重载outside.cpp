#include <iostream>
//using namespace std;

class Vector
{
private:
    double i;
    double j;
    double k;
public:
	Vector();

    Vector(double _i, double _j, double _k)
    {
        i = _i;
        j = _j;
        k = _k;
    }

	void echo(const Vector& v)
	{
		std::cout<<v.i<<","<<v.j<<","<<v.k<<std::endl;
	}
    //Some other functionality...
};

Vector operator+(const Vector& p1, const Vector& p2)
{
	Vector temp(p1);
	temp += p2;
	return temp;
}

int main()
{
	Vector a(11.0,22.0,33.0),b(1.0,2.0,3.0),c(0,0,0);
	c = a+b;
	c.echo(c);
	std::cin.get();
	return 0;
}