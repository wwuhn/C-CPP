#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include <sstream>

template<typename Target =string, typename Source =string>
Target to(Source arg) // convert Source to Target
{
	stringstream interpreter;
	Target result;
	if (   !(interpreter << arg)            // write arg into stream
		|| !(interpreter >> result)         // read result from stream
		|| !(interpreter >> std::ws).eof()) // stuff left in stream?
		throw runtime_error{"to<>() failed"};
	return result;
}

int main()
{
	
	ostringstream oss; // output memory for writing to a string
	oss<<"{temperature,"<<scientific<<123.4567890 << "}";
	cout<<oss.str()<<endl; // {temperature,1.234568e+002}
	
    string src="If you are a boy!";  
    istringstream iss(src);  // input memory for reading from a string
    string dst;  
    while(iss>>dst)  
    {  
        cout<<dst<<endl;  
    }  

	system("pause");
	return 0;
    
}
/*
{temperature,1.234568e+002}
If
you
are
a
boy!
*/