#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main()
{
	
	int ia[7] = {26,210,12,47,109,83,40};
	vector<int,allocator<int> > vi(ia,ia+7);	// ·ÖÅäÆ÷Ò²ÊÇÒ»¸öÄ£°å£¬ĞèÒª¸æËßËüÃ¿´Î·ÖÅäµÄÊÇÊ²Ã´¶«Î÷
	int n = count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(),40)));
	cout<<n;// Í³¼ÆĞ¡ÓÚ40µÄ·ñ¶¨µÄÔªËØÊıÁ¿£¬5
	cout<<"\nvector is container"<<endl;
	cout<<"allocator is allocator"<<endl;
	cout<<"count_if is algorithm"<<endl;
	cout<<"vi.begin is iterator"<<endl;
	cout<<"not1 is function adapter(negator)"<<endl;
	cout<<"bind2nd is function adapter(binder)"<<endl;
	cout<<"less is function object"<<endl;
    system("pause");
	return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
// system("pause");
// getchar();ÿ