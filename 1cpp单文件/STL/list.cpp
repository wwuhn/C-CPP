#include <iostream>  
#include <list>  
using namespace std;  
  
void main()  
{  
    list<int> c1;  
    c1.push_back(1);//��β��push���ݣ���㣩��list��   
    c1.push_back(2);   
    c1.push_back(3);  
    c1.push_back(4);  
      
    c1.push_front(0);//��ͷ��push���ݣ���㣩��list��   
      
    c1.pop_back();//��β��pop���ݣ���㣩��ȥ   
    int& i = c1.back();//��ȡlist��β�����ݣ���㣩   
    const int& ii = c1.front();//��ȡlist��ͷ�� ���ݣ���㣩  
      
      
    cout << "The last integer of c1 is " << i << endl;  
    cout << "The front interger of c1 is " << ii << endl;  
      
    cout << "forѭ���������ݾ�����" << endl;  
    //ѭ���������ݾ���  
    list<int>::iterator it; //�������ָʾ��(������int i=0)   
    for(it = c1.begin() ; it != c1.end() ;it++)  
    {  
        cout << *it << endl;  
    }  
    system("pause");  
}  