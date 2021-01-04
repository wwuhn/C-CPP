//---------------------------------------------------
/*
���yԇ hash_multiset, hash_multimap �^����������K��
headers <hash_set> �� <hash_map> ���Ѓɂ���
�քe�� ...\4.9.2\include\c++\backward �� ...\4.9.2\include\c++\ext��
��֪Ҫ����һ�M! 
�� <ext\...> ��һ�M���І��} 
   ...\4.9.2\include\c++\backward\hashtable.h 
   [Error] no match for call to '(const hasher {aka const __gnu_cxx::hash<std::basic_string<char> >}) (const key_type&)'
�� <backward\...> ��һ�M����ͬ�Ć��}.  
so, �ŗ��yԇ (no insertion or push_back or ...).  
*/
 
#include <ext\hash_set>       
    //...\4.9.2\include\c++\backward\backward_warning.h 
    //[Warning] #warning This file includes at least one deprecated or antiquated header 
    //which may be removed without further notice at a future date. 
    //Please use a non-deprecated interface with equivalent functionality instead. 
    //For a listing of replacement headers and interfaces, consult the file backward_warning.h. 
    //To disable this warning use -Wno-deprecated. [-Wcpp]
     
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj11
{
void test_hash_multiset(long& value)
{
    cout << "\ntest_hash_multiset().......... \n";
    
    __gnu_cxx::hash_multiset<string> c;   
    char buf[10];
             
    clock_t timeStart = clock();                                
    for(long i=0; i< value; ++i)
    {
        try {
            snprintf(buf, 10, "%d", rand());
            //! c.insert(string(buf));          
        }
        catch(exception& p) {
            cout << "i=" << i << " " << p.what() << endl; 
            abort();
        }
    }
    cout << "milli-seconds : " << (clock()-timeStart) << endl;                
}                                                            
}