#include<iostream>
using namespace std;

class Vector {
public:
	Vector(int s);
	int size();
	double& operator[](int i);
private:
	double* elem;   // pointer to the elements
	int sz;         // the number of elements
};

Vector::Vector(int s) // construct a Vector
{
	sz = s;
	elem = new double[s];
}

double& Vector::operator[](int i) // element access: subscripting
{ 
	return elem[i]; 
} 

int Vector::size() 
{ 
	return sz; 
}

double read_and_sum(int n)
{
	Vector v(n); // make a vector of s elements
	for (int i=0; i!=v.size(); ++i)
		cin>>v[i]; //read into elements
	double sum = 0;
	for (i=0; i!=v.size(); ++i)
		sum+=v[i]; //take the sum of the elements
	return sum;
}

void main()
{
	
    cout<< read_and_sum(6)<<endl;
    system("pause");
}
/*
1 2 3 4.4 5 6.6
22
*/