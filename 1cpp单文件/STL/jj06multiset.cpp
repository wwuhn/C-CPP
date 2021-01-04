#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm>
#include <string.h>
using namespace std;
//#define snprintf _snprintf
string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", (int)target);
	return string(buf);
}
//���� MyString �Ǟ��˜yԇ containers with moveable elements Ч��.  
class MyString { 
public: 
    static size_t DCtor;  	//��Ӌ default-ctor �ĺ��дΔ� 
    static size_t Ctor;  	//��Ӌ ctor      �ĺ��дΔ� 
    static size_t CCtor;  	//��Ӌ copy-ctor �ĺ��дΔ� 
    static size_t CAsgn;  	//��Ӌ copy-asgn �ĺ��дΔ� 
    static size_t MCtor;  	//��Ӌ move-ctor �ĺ��дΔ� 
    static size_t MAsgn;  	//��Ӌ move-asgn �ĺ��дΔ� 		    
    static size_t Dtor;	//��Ӌ dtor �ĺ��дΔ� 
private:     
    char* _data; 
    size_t _len; 
    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
public: 
    //default ctor
    MyString() : _data(NULL), _len(0) { ++DCtor;  }
    
    //ctor
    MyString(const char* p) : _len(strlen(p)) { 
        ++Ctor; 
        _init_data(p); 
    } 
    
    // copy ctor
    MyString(const MyString& str) : _len(str._len) { 
        ++CCtor;  	  
        _init_data(str._data); 	//COPY
    } 
    
    //move ctor, with "noexcept"
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len)  {  
        ++MCtor;    
        str._len = 0; 		
        str._data = NULL;  	//���� delete (in dtor) 
    }
    
    //copy assignment
    MyString& operator=(const MyString& str) { 
        ++CAsgn;  	 
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data); 	//COPY! 
        } 
        else {
            // Self Assignment, Nothing to do.   
        }
        return *this; 
    } 
    
    //move assignment
   	MyString& operator=(MyString&& str) noexcept { 	 
        ++MAsgn;   	
        if (this != &str) { 
            if (_data) delete _data; 
            _len = str._len; 
            _data = str._data;	//MOVE!
            str._len = 0; 
            str._data = NULL; 	//���� deleted in dtor 
        } 
        return *this; 
    }
    
    //dtor
    virtual ~MyString() { 	
        ++Dtor;	      	  	    
        if (_data) {
            delete _data; 	
        }
    }   	
    
    bool 
        operator<(const MyString& rhs) const	//����׌ set ���^��С  
    {
        return std::string(this->_data) < std::string(rhs._data); 	//��������string ���ܱ��^��С. 
    }
    bool 
        operator==(const MyString& rhs) const	//����׌ set �Д����. 
    {
        return std::string(this->_data) == std::string(rhs._data); 	//��������string �����Д����. 
    }	
    
    char* get() const { return _data; }
}; 
size_t MyString::DCtor=0;  	
size_t MyString::Ctor=0;  	 
size_t MyString::CCtor=0;
size_t MyString::CAsgn=0;
size_t MyString::MCtor=0;
size_t MyString::MAsgn=0;
size_t MyString::Dtor=0;

namespace std 	//��횷��� std �� 
{
    template<> 
        struct hash<MyString> 	//�@�Ǟ��� unordered containers 
    {
        size_t 
            operator()(const MyString& s) const noexcept
        {  return hash<string>()(string(s.get()));  }  
        //���ìF�е� hash<string> (in ...\include\c++\bits\basic_string.h)
    };
}
//-----------------
//���� MyStrNoMove �Ǟ��˜yԇ containers with no-moveable elements Ч��.  
class MyStrNoMove { 
public: 
    static size_t DCtor;  	//��Ӌ default-ctor �ĺ��дΔ� 
    static size_t Ctor;  	//��Ӌ ctor      �ĺ��дΔ� 
    static size_t CCtor;  	//��Ӌ copy-ctor �ĺ��дΔ� 
    static size_t CAsgn;  	//��Ӌ copy-asgn �ĺ��дΔ� 
    static size_t MCtor;  	//��Ӌ move-ctor �ĺ��дΔ� 
    static size_t MAsgn;  	//��Ӌ move-asgn �ĺ��дΔ� 		    
    static size_t Dtor;	    //��Ӌ dtor �ĺ��дΔ� 
private:     
    char* _data; 
    size_t _len; 
    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
public: 
    //default ctor
    MyStrNoMove() : _data(NULL), _len(0) { 	++DCtor; _init_data("jjhou"); }
    
    //ctor
    MyStrNoMove(const char* p) : _len(strlen(p)) { 
        ++Ctor;  _init_data(p); 
    } 
    
    // copy ctor
    MyStrNoMove(const MyStrNoMove& str) : _len(str._len) { 
        ++CCtor;  	 
        _init_data(str._data); 	//COPY
    } 
    
    //copy assignment
    MyStrNoMove& operator=(const MyStrNoMove& str) { 
        ++CAsgn;
        
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data); 	//COPY! 
        } 
        else {
            // Self Assignment, Nothing to do.   
        }
        return *this; 
    } 
    
    //dtor
    virtual ~MyStrNoMove() { 	   
        ++Dtor;		  	    
        if (_data) {
            delete _data; 	
        }
    }   	
    
    bool 											
        operator<(const MyStrNoMove& rhs) const		//����׌ set ���^��С 
    {
        return string(this->_data) < string(rhs._data);  //��������string ���ܱ��^��С. 
    }  	
    
    bool 											
        operator==(const MyStrNoMove& rhs) const	//����׌ set �Д����. 
    {
        return string(this->_data) == string(rhs._data);  //��������string �����Д����. 
    } 
    
    char* get() const { return _data; }	
}; 
size_t MyStrNoMove::DCtor=0;  	
size_t MyStrNoMove::Ctor=0;  
size_t MyStrNoMove::CCtor=0;
size_t MyStrNoMove::CAsgn=0;
size_t MyStrNoMove::MCtor=0;
size_t MyStrNoMove::MAsgn=0;
size_t MyStrNoMove::Dtor=0;

namespace std 	//��횷��� std �� 
{
    template<> 
        struct hash<MyStrNoMove> 	//�@�Ǟ��� unordered containers 
    {
        size_t 
            operator()(const MyStrNoMove& s) const noexcept
        {  return hash<string>()(string(s.get()));  }  
        //���ìF�е� hash<string> (in ...\4.9.2\include\c++\bits\basic_string.h)
    };
}

#include <typeinfo>  //typeid()
template<typename T>
void output_static_data(const T& myStr)
{
	cout << typeid(myStr).name() << " -- " << endl; 
	cout << " CCtor=" << T::CCtor 	
		 << " MCtor=" << T::MCtor 
	     << " CAsgn=" << T::CAsgn 		 
		 << " MAsgn=" << T::MAsgn 
		 << " Dtor="  << T::Dtor 
		 << " Ctor="  << T::Ctor 
		 << " DCtor=" << T::DCtor 		 
		 << endl;	
}

#include <ctime>  //clock_t, clock()
template<typename M, typename NM>	
void test_moveable(M c1, NM c2, long& value)
{ 	
char buf[10];
			
	//�yԇ move 
	cout << "\n\ntest, with moveable elements" << endl;			
	typedef typename iterator_traits<typename M::iterator>::value_type  V1type; 	
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c1.end();
        c1.insert(ite, V1type(buf));	
	}
	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c1.size() << endl;		
	output_static_data(*(c1.begin()));

	timeStart = clock();	
M c11(c1);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
M c12(std::move(c1));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c11.swap(c12);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;		

	
	
	//�yԇ non-moveable 	
	cout << "\n\ntest, with non-moveable elements" << endl;		
	typedef typename iterator_traits<typename NM::iterator>::value_type  V2type; 				
    timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c2.end();
        c2.insert(ite, V2type(buf));	
	}

	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c2.size() << endl;			
	output_static_data(*(c2.begin()));

	timeStart = clock();	
NM c21(c2);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
NM c22(std::move(c2));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c21.swap(c22);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;			
}	
namespace jj06
{
    void test_multiset(long& value)
    {
        cout << "\ntest_multiset().......... \n";
        
        multiset<string> c;  	
        char buf[10];		
        clock_t timeStart = clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                c.insert(string(buf));     				
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;	
        cout << "multiset.size()= " << c.size() << endl;	
        cout << "multiset.max_size()= " << c.max_size() << endl;	//214748364
        
        string target = get_a_target_string();	
        {
            timeStart = clock();
            auto pItem = find(c.begin(), c.end(), target);	//�� c.find(...) ���ܶ�	
            cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found! " << endl;	
        }
        
        {
            timeStart = clock();		
            auto pItem = c.find(target);		//�� std::find(...) ��ܶ�							
            cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found! " << endl;	
        }	
        
        c.clear();
        test_moveable(multiset<MyString>(),multiset<MyStrNoMove>(), value);	 						
    }															 
}


int main()
{
    long value = 100000;
    jj06::test_multiset(value);
    printf("finished");
    
    while(1);
    return 0;
}
/*

test_multiset().......... 
milli-seconds : 377992
multiset.size()= 100000
multiset.max_size()= 461168601842738790
target (0~2147483647): 12356
std::find(), milli-seconds : 26880
not found! 
c.find(), milli-seconds : 15
not found! 


test, with moveable elements
construction, milli-seconds : 1555164
size()= 100000
8MyString -- 
 CCtor=0 MCtor=100000 CAsgn=0 MAsgn=0 Dtor=100000 Ctor=100000 DCtor=0
copy, milli-seconds : 56550
move copy, milli-seconds : 1
swap, milli-seconds : 6


test, with non-moveable elements
construction, milli-seconds : 1458436
size()= 100000
11MyStrNoMove -- 
 CCtor=100000 MCtor=0 CAsgn=0 MAsgn=0 Dtor=100000 Ctor=100000 DCtor=0
copy, milli-seconds : 45020
move copy, milli-seconds : 5
swap, milli-seconds : 2
finished

*/