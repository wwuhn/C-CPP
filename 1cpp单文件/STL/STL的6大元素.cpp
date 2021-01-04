#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main()
{
	
	int ia[7] = {26,210,12,47,109,83,40};
	vector<int,allocator<int> > vi(ia,ia+7);	// ������Ҳ��һ��ģ�壬��Ҫ������ÿ�η������ʲô����

	int n = count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(),40)));
	cout<<n;// ͳ��С��40�ķ񶨵�Ԫ��������5

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
