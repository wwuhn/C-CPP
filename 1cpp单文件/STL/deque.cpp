#include <iostream>  
#include <deque>  
using namespace std;  

void printDeque(const deque<int>& d)  
{  
    cout<<"\nʹ���±�:\n";  
    for (unsigned int i = 0; i < d.size(); i++)  
    {  
        cout<<"d["<<i<<"] = "<<d[i]<<", ";  
    }  
    
    cout<<"\nʹ�õ�����\n";  
    deque<int>::const_iterator iter = d.begin();  
    for (;iter != d.end(); iter ++)  
    {  
        cout<<"d["<<iter-d.begin()<<"] = "<<(*iter)<<", ";  
    }  
    cout<<endl;  
}  

void main()  
{  
    //����deque  
    deque<int> d1;                          //����һ��û���κ�Ԫ�ص�deque����  
    deque<int> d2(10);                      //����һ������10��Ԫ�ص�deque����ÿ��Ԫ��ֵΪĬ��  
    deque<double> d3(10, 5.5);              //����һ������10��Ԫ�ص�deque����,ÿ��Ԫ�صĳ�ʼֵΪ5.5  
    deque<double> d4(d3);                   //ͨ������һ��deque�����Ԫ��ֵ, ����һ���µ�deque����  
    
    //��ʼ����ֵ��ͬvectorһ��,ʹ��β�����뺯��push_back()  
    for (int i = 1; i < 6 ; i++)  
        d1.push_back(i*10);  
    
    
    //����Ԫ��: 1-�±귽ʽ 2-��������ʽ ����������ԣ�  
    cout<<"printDeque(d1) : "<<endl;  
    printDeque(d1);  
    
    //Ԫ�ز��룺β��������push_back()��ͷ��������push_front()������λ�ò�����insert(&pos, elem)  
    cout<<"d1.push_front(100): "<<endl;  
    d1.push_front(100);  
    printDeque(d1);  
    cout<<"d1.insert(d1.begin()+3, 200): "<<endl; //֧�������ȡ(��[]������)������begin()����+3  
    d1.insert(d1.begin()+2,200);  
    printDeque(d1);  
    
    //Ԫ��ɾ�� β��ɾ����pop_back();ͷ��ɾ����pop_front();   
    //�������λ�û���������ϵ�Ԫ��ɾ����erase(&pos)/erase(&first, &last)��ɾ������Ԫ����clear();  
    cout<<"d1.pop_front(): "<<endl;  
    d1.pop_front();  
    printDeque(d1);  
    
    cout<<"d1.erase(d1.begin()+1): "<<endl;  
    d1.erase(d1.begin()+1); //ɾ����2��Ԫ��d1[1]  
    printDeque(d1);  
    
    cout<<"d1.erase(d1.begin(), d1.begin() + 2) = "<<endl;  
    d1.erase(d1.begin(), d1.begin() + 2);  
    printDeque(d1);  
    
    cout<<"d1.clear() :"<<endl;  
    d1.clear();  
    printDeque(d1);  
    
    system("pause");
    
}  