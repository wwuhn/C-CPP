#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include <sstream>

template<typename Target =string, typename Source =string>
Target to(Source arg)       // convert Source to Target
{
	stringstream interpreter;
	Target result;
	interpreter << arg;     // write arg into stream
	interpreter >> result;  // read result from stream
	return result;
}

int main()
{
	string s = to<string,double>(1.2);
	cout<<s<<endl;

	double d = to<double,string>("1.2");
	cout<<d*2<<endl;;
	
	system("pause");
	return 0;
 
}

/*
1.2
2.4
/*