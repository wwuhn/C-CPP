#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct Person
{
	string fname;
	string lname;
	Person(string a,string b):fname(a),lname(b){}
};

class person_sort_rule
{
public:
	bool operator()(Person p1,Person p2)
	{
		return (p1.fname<p2.fname);
	}
};

int main()
{
	typedef set<Person,person_sort_rule> personSet;
	personSet ps;
	ps.clear();
	Person t1("wu","wq");
	ps.insert(t1);
	Person t2("li","bing");
	ps.insert(t2);
	Person t3("liu","ym");
	ps.insert(t3);
	personSet::iterator it;
	for(it=ps.begin();it!=ps.end();it++)
		cout<<it->fname<<" "<<it->lname<<endl;
    cin.get();
	return 0;
}
/*
li bing
liu ym
wu wq
*/