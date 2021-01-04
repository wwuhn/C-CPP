#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int,int> m;
	m.insert(pair<int,int>(1,11));
	m.insert(make_pair(2,22));
	m.insert(map<int,int>::value_type(3,33));
	m[4]=44;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		//cout<<"key:"<<it->first<<" value: "<<it->second<<endl;
	}
	for(int i=1; i<=4; i++)
	{
		cout<<"key:"<<i<<" value: "<<m[i]<<endl;
	}
	cin.get();

	return 0;
}
/*output:
key:1 value: 11
key:2 value: 22
key:3 value: 33
key:4 value: 44
*/