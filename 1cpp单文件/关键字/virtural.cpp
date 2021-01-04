#include <iostream>
#include <string>
using namespace std;

class Graph
{
	protected:
		double x;
		double y;
	public:
		Graph(double x, double y);
		virtual void showArea();
};

Graph::Graph(double x,double y)
{
	this->x=x;
	this->y=y;
}

void Graph::showArea()
{
	cout<<"couting Graph's Area"<<endl;
}

class Rectangle:public Graph
{
	public:
		Rectangle(double x, double y):Graph(x,y){};
		void showArea();
};

void Rectangle::showArea()
{
	cout<<"Rectangle's area: "<<x*y<<endl;
}

class Triangle:public Graph{
	public:
		Triangle(double d, double h):Graph(d,h){};
		void showArea();
};

void Triangle::showArea()
{
	cout<<"Triangle's area: "<<x*y*0.5<<endl;
}

class Circle:public Graph
{
	public:
		Circle(double r):Graph(r,r){};
		void showArea();
};

void Circle::showArea()
{
	cout<<"Circle's Area: "<<3.14*x*y<<endl;
}

int main()
{
	Graph * g;
	Rectangle rec(8,5);
	g = &rec;
	g->showArea();
	Triangle tri(6,5);
	g = &tri;
	g->showArea();
	Circle cir(2);
	g = &cir;
	g->showArea();
	system("pause");
	return 0;
}
/*
Rectangle's area: 40
Triangle's area: 15
Circle's Area: 12.56
*/
