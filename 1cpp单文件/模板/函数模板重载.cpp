#include<iostream>
using namespace std;

template <typename T>					// ����ģ��
T Max( const T a, const T b )  
{ 
	return a>b ? a : b ; 
}

template <typename T>					// ���غ���ģ��
T Max( const T a, const T b , const T c)
{ 
	T t ;  
	t = Max(a, b) ;    
	return Max ( t, c ) ;  
}

int Max(const int a , const char b )	// ����ͨ�������غ���ģ��
{ 
	return a>b ? a : b ; 
}

int main()
{ 
	cout << " Max(3,    'a' )   is "	<< Max(3,	'a' )	<< endl ;
    cout << " Max(9.3,  0.5 )   is "	<< Max(9.3, 0.5	)	<< endl ;
    cout << " Max(9,    5,  23) is "	<< Max(9,	5,	23) << endl ;
	getchar();
}
