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
	friend Vector operator+(const Vector& n1, const Vector& n2);
    Vector(double _i, double _j, double _k)
    {
        i = _i;
        j = _j;
        k = _k;
    }

    Vector& operator+=(const Vector& p1)
    {
        i += p1.i;
        j += p1.j;
        k += p1.k;
        return *this;
    }

	void echo(const Vector& v)
	{
		std::cout<<v.i<<","<<v.j<<","<<v.k<<std::endl;
	}

    Vector operator+(const Vector & p2)
    {
        Vector temp(*this);
        temp += p2;
        return temp;
    }
	
    //Some other functionality...
};

int main()
{
	Vector a(11.0,22.0,33.0),b(1.0,2.0,3.0),c(0,0,0);
	c = a+b;
	c.echo(c);
	std::cin.get();
	return 0;
}