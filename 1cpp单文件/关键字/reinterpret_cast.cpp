#include <iostream>
using namespace std;

int main()
{
	double d = 3.14;
	void* p = &d;
	double *dp = static_cast<double*>(p);
	
	int i;
	float f = 166.71;
	i = static_cast<int>(f);
	cout<<i<<endl;  // 166

	int k;
	char *p2 = "This is an example.";
	k = reinterpret_cast<int>(p2);	 //
	cout<<k<<endl;  //4648988
    cin.get();
	return 0;
}
/*
166
4648988
*/