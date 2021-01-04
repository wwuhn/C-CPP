#include <iostream.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> intVector( 5 );
void main()
{
	intVector[3-1] = 33;
	for ( int i = 1; i <= 15; i++ )
	{
		intVector.push_back( i );
	}
	vector<int>::iterator intIter =	\
		find( intVector.begin(), intVector.end(), 12 );
	if ( intIter != intVector.end() )
		cout << "Vector contains value " << *intIter << endl;
	else
		cout << "Vector does not contain 12" << endl;
	for ( intIter = intVector.begin(); \
	      intIter != intVector.end(); ++intIter )
	{
		cout << *intIter << " ";
	}
	cin.get();
}
/*output:
Vector contains value 12
0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/