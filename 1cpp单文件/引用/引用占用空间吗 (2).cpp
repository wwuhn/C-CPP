#include <iostream>
using namespace std;

void main()
{
	int j=3;
	int var=4;							
	int* p = &var;												
	int& f = var;
	f=8;
	int i = 5;
	cout<<&j<<endl;
	cout<<&var<<endl;
	cout<<&p<<endl;
	cout<<&f<<endl;
	cout<<&i<<endl;
    system("pause");
}
/*输出
0012FF44
0012FF40
0012FF3C
0012FF40
0012FF34
*/

/*在Debug下的汇编，在release下可能有优化
6:        int j=3;
00401578   mov         dword ptr [ebp-4],3
7:        int var=4;
0040157F   mov         dword ptr [ebp-8],4
8:        int* p = &var;
00401586   lea         eax,[ebp-8]
00401589   mov         dword ptr [ebp-0Ch],eax
9:        int& f = var;
0040158C   lea         ecx,[ebp-8]
0040158F   mov         dword ptr [ebp-10h],ecx
*/

#if 0
#include <iostream>
using namespace std;
void main()
{
	
	int j=3;
	int var=4;							
	int* p = &var;												
	int& f = var;
	f=8;
	int i = 5;
	cout<<&j<<endl;
	cout<<&var<<endl;
	cout<<&p<<endl;
	cout<<&f<<endl;
	cout<<&i<<endl;
 system("pause");
}
/*输出
0012FF44
0012FF40
0012FF3C
0012FF40
0012FF34
*/
#endif