#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main()
{
	int ia[7] = {26,210,12,47,109,83};
	vector<int,allocator<int> > vi(ia,ia+6);
	int i = count_if(vi.begin(), vi.end(), 
		             not1(bind2nd(less<int>(),40)));
	cout<<i;
	return 0;
}