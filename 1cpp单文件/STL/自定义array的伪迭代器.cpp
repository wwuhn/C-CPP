#include <iostream>
using namespace std;

template <typename T>
class array
{
private:
	T* head;
	size_t len;
public:
	array():head(nullptr),len(0){}

	array(size_t l, T* list):head(new T[l]),len(l)
	{
		for(size_t i=0;i<l;++i)
			head[i] = list[i];
	}

	~array(){delete[] head;}

	typedef T* iterator;
	iterator begin() {return head;}
	iterator end() {return head+len;}
};

int main()
{ 
	int arr[] = {1,2,3,4,5,6,7};
	array<int> a(sizeof(arr) /sizeof(int),arr);
	for(array<int>::iterator itr = a.begin();itr!=a.end();++itr)
		cout<<*itr<<' ';
	cin.get();
    return 0;
}
