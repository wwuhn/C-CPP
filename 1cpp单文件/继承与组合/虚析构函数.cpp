#include <iostream>
using namespace std;

class CSon
{
public:
	~CSon(){cout<<"bye from son"<<endl;}
	//virtual ~CSon(){cout<<"bye from son"<<endl;}
};

class CGrandson:public CSon
{
public:
	~CGrandson(){cout<<"bye from grandson"<<endl;}
};

void main()
{
	CSon *pson=new CGrandson;
	delete pson;
	system("pause");
}
//bye from son
