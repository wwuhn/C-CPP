#include <iostream>
using namespace std;

class DivideByZeroException {
public:
	DivideByZeroException()
		: message( "attempted to divide by zero" ) { }
	const char *what() const { return message; }
private:
	const char *message;
};

double Div(int x, int y )
{
    if ( y == 0 )
		throw DivideByZeroException();
	
    return static_cast<double> ( x ) / y;
}

int main()
{  
	int number1, number2;
	double result;
	cout << "Enter two integers (end-of-file to end): ";
	while ( cin >> number1 >> number2 ) 
    {
		try 
        { 
            result = Div( number1, number2 );
		    cout << "The quotient is: " << result << endl;
		}   
		catch ( DivideByZeroException ex ) 
        {
			cout << "Exception occurred: "   << ex.what() << '\n';   
        }
		cout << "\nEnter two integers (end-of-file to end):"; //eof
	}
	cout << endl;	
    system("pause");
	return 0;
}
