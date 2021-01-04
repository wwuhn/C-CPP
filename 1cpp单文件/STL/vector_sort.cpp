#include <iostream>  
#include <algorithm>  
#include <stdlib.h>  
#include <time.h>  
#include <VECTOR>  
using namespace std;  

const int N=10;  
void print(const vector<int>& v)  
{  
    vector<int>::const_iterator ite=v.begin();  
    for(;ite!=v.end();ite++)  
    {  
        cout<<*ite<<"  ";  
    }  
    cout<<endl;  
}  

void Create(vector<int>& v)  
{  
    srand((unsigned int)time(NULL));  
    v.resize(N);  
    for(int i=0;i<N;i++)  
        v[i]=rand()%100;  
}

void sort1(vector<int> v)  
{  
    sort(v.begin(),v.end());  
    cout<<"after sort funtion:\n";  
    print(v);  
}  
  
void sort2(vector<int> v)  
{  
    stable_sort(v.begin(),v.end());  
    cout<<"after stable_sort funtion:\n";  
    print(v);  
}  
  
void sort3(vector<int> v)  
{  
    partial_sort(v.begin(),v.begin()+v.size()/2,v.end()); //对前半部分排序  
    cout<<"after partial_sort funtion:\n";  
    print(v);  
}  
  
void sort4(vector<int> v)  
{  
    vector<int> temp;  
    temp.resize(v.size());  
    partial_sort_copy(v.begin(),v.end(),temp.begin(),temp.end()); //复制并排序  
    cout<<"after partial_sort_copy funtion:\n";  
    print(temp);  
}  
  
void main()  
{  
    vector<int> v;  
    Create(v);  
    cout<<"before sort:\n";  
    print(v);  

    sort1(v);  
    sort2(v);  
    sort3(v);  
    sort4(v);  
	system("pause");
}
/*
before sort:
48  13  10  21  0  81  44  21  29  73
after sort funtion:
0  10  13  21  21  29  44  48  73  81
after stable_sort funtion:
0  10  13  21  21  29  44  48  73  81
after partial_sort funtion:
0  10  13  21  21  81  48  44  29  73
after partial_sort_copy funtion:
0  10  13  21  21  29  44  48  73  81
*/  