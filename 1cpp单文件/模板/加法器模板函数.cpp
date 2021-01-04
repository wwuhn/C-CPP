#include <cstdio>
#include <cstdlib>

template<class T>
T add(T m, T n)
{
	return m + n;
}

int main()
{ 
	
	float i;
	i = add<float>(4.1, 7);
	printf("%f\n",i);
	system("pause");                 
	return 0;
}
//11.100000
