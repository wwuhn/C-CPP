#include <iostream>
using namespace std;

class V {
	int *pv;
public:
	V(int a) { pv = new int; *pv = a; }
	~V( ) { delete pv;}

	void disp( ) {
		cout << "This=" << this << endl;
		cout << "pv=" << pv << endl;
		cout << "*pv=" << *pv << endl;
	}

	V(const V& s) {
		pv = new int;
		*pv = *s.pv;
	}
};

int main()
{
	
	V a(3);
	V b(5);
	a.disp();
	b.disp();
	
	V b2 = a;
	
	//*b.pv=100;
	a.disp( );
	b2.disp( );
	system("pause");
	return 0;
}
/*
This=0012FF38
pv=00512C60
*pv=3
This=0012FF34
pv=00512CA8
*pv=5
This=0012FF38
pv=00512C60
*pv=3
This=0012FF30
pv=00512D90
*pv=3
*/