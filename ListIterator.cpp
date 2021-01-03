#include <iostream>
using namespace std;

template <typename T>
class linkedList
{
private:
	struct node
	{
		int data;
		node * next;
	};
	typedef node* NODEPTR;
	
public:
	NODEPTR head;
	linkedList():head(NULL){}

	linkedList& push_front(int e)
	{
		NODEPTR p = new node;
		p->data = e;
		p->next = NULL;
		if(head!=NULL)
			p->next = head;
		head = p;
		return *this;
	}

	typedef NODEPTR _range;
	class iterator
	{
	private:
		_range p;
	public:
		iterator():p(NULL){}
		iterator(const linkedList& ll):p(ll.head){}

		iterator & operator+(const iterator& itr)
		{
			p=itr.p;
			return *this;
		}

		iterator& operator++()
		{
			p = p->next;
			return *this;
		}

		bool operator != (const iterator& itr)
		{
			return p!= itr.p;
		}

		T& operator *()
		{
			return p->data;
		}
	};

	iterator begin()
	{
		return iterator(*this);
	}
	iterator end()
	{
		return iterator();
	}
};

int main()
{ 
	linkedList<int> list;
	for(int i=0;i<=5;i++)
		list.push_front(i);
	
	for(linkedList<int>::iterator itr = list.begin();
			itr!=list.end();++itr)
		cout<<*itr<<' ';
	cin.get();
 return 0;
}
//5 4 3 2 1 0
