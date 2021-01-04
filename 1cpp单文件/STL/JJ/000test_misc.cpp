
const long ASIZE  =   500000L;
 
//----------------------------------------------------
#include <iostream>
#include <cstdio>  //snprintf()
#include <cstdlib> //RAND_MAX
#include <cstring> //strlen(), memcpy()
#include <string> 
using std::cin;
using std::cout;
using std::string;
using namespace std;

//���� MyString �Ǟ��˜yԇ containers with moveable elements Ч��.  
class MyString { 
public: 
    static size_t DCtor;    //��Ӌ default-ctor �ĺ��дΔ� 
    static size_t Ctor;     //��Ӌ ctor      �ĺ��дΔ� 
    static size_t CCtor;    //��Ӌ copy-ctor �ĺ��дΔ� 
    static size_t CAsgn;    //��Ӌ copy-asgn �ĺ��дΔ� 
    static size_t MCtor;    //��Ӌ move-ctor �ĺ��дΔ� 
    static size_t MAsgn;    //��Ӌ move-asgn �ĺ��дΔ�            
    static size_t Dtor; //��Ӌ dtor �ĺ��дΔ� 
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
        _init_data(str._data);  //COPY
    } 
 
    //move ctor, with "noexcept"
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len)  {  
        ++MCtor;    
        str._len = 0;       
        str._data = NULL;   //���� delete (in dtor) 
    }
  
    //copy assignment
    MyString& operator=(const MyString& str) { 
        ++CAsgn;     
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data);  //COPY! 
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
            _data = str._data;  //MOVE!
            str._len = 0; 
            str._data = NULL;   //���� deleted in dtor 
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
    operator<(const MyString& rhs) const //����׌ set ���^��С  
    {
       return std::string(this->_data) < std::string(rhs._data);  //��������string ���ܱ��^��С. 
    }
    bool
    operator==(const MyString& rhs) const   //����׌ set �Д����. 
    {
       return std::string(this->_data) == std::string(rhs._data);    //��������string �����Д����. 
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
 
namespace std   //��횷��� std �� 
{
template<> 
struct hash<MyString>     //�@�Ǟ��� unordered containers 
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
    static size_t DCtor;    //��Ӌ default-ctor �ĺ��дΔ� 
    static size_t Ctor;     //��Ӌ ctor      �ĺ��дΔ� 
    static size_t CCtor;    //��Ӌ copy-ctor �ĺ��дΔ� 
    static size_t CAsgn;    //��Ӌ copy-asgn �ĺ��дΔ� 
    static size_t MCtor;    //��Ӌ move-ctor �ĺ��дΔ� 
    static size_t MAsgn;    //��Ӌ move-asgn �ĺ��дΔ�            
    static size_t Dtor;     //��Ӌ dtor �ĺ��дΔ� 
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
    MyStrNoMove() : _data(NULL), _len(0) {  ++DCtor; _init_data("jjhou"); }
 
    //ctor
    MyStrNoMove(const char* p) : _len(strlen(p)) { 
        ++Ctor;  _init_data(p); 
    } 
 
    // copy ctor
    MyStrNoMove(const MyStrNoMove& str) : _len(str._len) { 
        ++CCtor;     
        _init_data(str._data);  //COPY
    } 
 
    //copy assignment
    MyStrNoMove& operator=(const MyStrNoMove& str) { 
        ++CAsgn;
 
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data);  //COPY! 
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
    operator<(const MyStrNoMove& rhs) const      //����׌ set ���^��С 
    {
       return string(this->_data) < string(rhs._data);  //��������string ���ܱ��^��С. 
    }   
     
    bool                                           
    operator==(const MyStrNoMove& rhs) const    //����׌ set �Д����. 
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
 
namespace std   //��횷��� std �� 
{
template<> 
struct hash<MyStrNoMove>  //�@�Ǟ��� unordered containers 
{
    size_t
    operator()(const MyStrNoMove& s) const noexcept
    {  return hash<string>()(string(s.get()));  }  
       //���ìF�е� hash<string> (in ...\4.9.2\include\c++\bits\basic_string.h)
};
}
 
//----------------------------------------------------

#include <iostream>
#include <cstdio>  //snprintf()
#include <cstdlib> //RAND_MAX
#include <string> 
#include <algorithm> 
#include <list> 
#include <forward_list> 
using std::cin;
using std::cout;
using std::string;
using std::max;
using std::min;
 
namespace jj00
{
     
bool strLonger(const string& s1, const string& s2) {
          return s1.size() < s2.size();
}       
     
void test_misc()
{
    cout << "\ntest_misc().......... \n";
      
    //�����@Щ�ǘ˜ʎ�ı��������� max_size() Ӌ�㷽ʽ.  
    cout << size_t(-1) << endl;                             //4294967295
    cout << size_t(-1)/sizeof(long) << endl;                //1073741823
    cout << size_t(-1)/sizeof(string) << endl;              //1073741823
    cout << size_t(-1)/sizeof(_List_node<string>) << endl;    //357913941
    cout << size_t(-1)/sizeof(_Fwd_list_node<string>) << endl; //536870911
    cout << "RAND_MAX= " << RAND_MAX << endl; //32767
     
    cout << min( {2,5,8,9,45,0,81} ) << endl;  //0
    cout << max( {2,5,8,9,45,0,81} ) << endl;  //81
    vector<int> v {2,5,8,9,45,0,81};               
          
    cout << "max of     zoo and hello : "
         << max(string("zoo"), string("hello")) << endl;              //zoo
    cout << "longest of zoo and hello : "
         << max(string("zoo"), string("hello"), strLonger) << endl;   //hello    
          
    cout << hash<MyString>()(MyString("Ace")) << endl;        //1765813650
    cout << hash<MyString>()(MyString("Stacy")) << endl;  //2790324277
    cout << "MyString(zoo) < MyString(hello) ==> " << (MyString("zoo") < MyString("hello")) << endl; //0
    cout << "MyString(zoo) == MyString(hello) ==> " << (MyString("zoo") == MyString("hello")) << endl; //0   
    cout << "MyStrNoMove(zoo) < MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") < MyStrNoMove("hello")) << endl;  //0
    cout << "MyStrNoMove(zoo) == MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") == MyStrNoMove("hello")) << endl;  //0
    //���Ͻ����� 6 �� MyString objects �� 4 �� MyStrNoMove objects�����Ǖ��r����.    
}
}    
//--------------------------------------------------
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
//-----------------
long get_a_target_long()
{
long target=0;
 
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}
 
string get_a_target_string()
{
long target=0;
char buf[10];
 
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}
 
int compareLongs(const void* a, const void* b)
{
  return ( *(long*)a - *(long*)b );
}
 
int compareStrings(const void* a, const void* b)
{
  if ( *(string*)a > *(string*)b )
        return 1;
  else if ( *(string*)a < *(string*)b )
        return -1;  
  else         
        return 0;  
}

int main()
{
    jj00::test_misc();      
    while(1);
    return 0;
}