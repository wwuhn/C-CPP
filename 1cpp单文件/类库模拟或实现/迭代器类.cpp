#include <iostream>
#include <string.h>
using namespace std;

class CPPCollection
{
public:
	//迭代器类
	class Iterator
	{
public:
    int index;//元素下标
    CPPCollection& outer;
    Iterator(CPPCollection &o, int i):outer(o), index(i){}
    void operator++()
    {
        index++;
    }
    std::string operator*() const
    {
        return outer.str[index];
    }
    bool operator!=(Iterator i)
    {
        return i.index!=index;
    }
};
public:
    CPPCollection()
    {
        string strTemp[10]={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        int i=0;
        for(auto strIt:strTemp)
        {
            str[i++]=strIt;
        }
    }
    Iterator begin()
    {
        return Iterator(*this,0);
    }
    Iterator end()
    {
        return Iterator(*this, 10);
    }
private:
    string str[10];
};

int main()
{
	CPPCollection cpc;
	for (auto i : cpc)
	{
		std::cout <<i<<std::endl;
	}
	//或者 CPPCollection cpc;
	for(CPPCollection::Iterator i= cpc.begin();i!=cpc.end();++i)
	{
		std::cout<<*i<<std::endl;
	}
	system("pause");
	return 1;
}