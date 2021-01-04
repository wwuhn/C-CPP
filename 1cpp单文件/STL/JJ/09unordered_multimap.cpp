#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
using namespace std;

long get_a_target_long()
{
long target=0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

namespace jj09
{
    void test_unordered_multimap(long& value)
    {
        cout << "\ntest_unordered_multimap().......... \n";
        
        unordered_multimap<long, string> c;  	
        char buf[10];
        
        clock_t timeStart = clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                //multimap ����ʹ�� [] �M�� insertion 
                c.insert(pair<long,string>(i,buf));
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;		
        cout << "unordered_multimap.size()= " << c.size() << endl;	
        cout << "unordered_multimap.max_size()= " << c.max_size() << endl;	//357913941	
        
        long target = get_a_target_long();		
        timeStart = clock();		
        auto pItem = c.find(target);								
        cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
        if (pItem != c.end())
            cout << "found, value=" << (*pItem).second << endl;
        else
            cout << "not found! " << endl;		
    }															 
}


int main()
{
    long value;
    jj09::test_unordered_multimap(value);
    printf("finished");
    while(1);
    return 0;
}
/*

test_unordered_multimap().......... 
milli-seconds : 2
unordered_multimap.size()= 0
unordered_multimap.max_size()= 768614336404564650
target (0~2147483647): 1235
c.find(), milli-seconds : 7
not found! 

*/