#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print(list<int>&lt)
{
	list<int>::iterator it;
	for(it=lt.begin();it!=lt.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}

class sequence
{
	int value;
public:
	sequence(int iv):value(iv){}
	int operator()()
	{
		return value++;
	}	
};

int main()
{
	list<int> lt;
	generate_n(back_inserter(lt),4,sequence(1)); // 函数对象值传递
	print(lt);

	sequence seq(11);
	generate_n(back_inserter(lt),5,seq); // 函数对象引用传递
	print(lt);
    cin.get();
	return 0;
}
/*
1 2 3 4
1 2 3 4 11 12 13 14 15
*/