#include <iostream>  
#include <deque>  
using namespace std;  

void printDeque(const deque<int>& d)  
{  
    cout<<"\n使用下标:\n";  
    for (unsigned int i = 0; i < d.size(); i++)  
    {  
        cout<<"d["<<i<<"] = "<<d[i]<<", ";  
    }  
    
    cout<<"\n使用迭代器\n";  
    deque<int>::const_iterator iter = d.begin();  
    for (;iter != d.end(); iter ++)  
    {  
        cout<<"d["<<iter-d.begin()<<"] = "<<(*iter)<<", ";  
    }  
    cout<<endl;  
}  

void main()  
{  
    //创建deque  
    deque<int> d1;                          //创建一个没有任何元素的deque对象  
    deque<int> d2(10);                      //创建一个具有10个元素的deque对象，每个元素值为默认  
    deque<double> d3(10, 5.5);              //创建一个具有10个元素的deque对象,每个元素的初始值为5.5  
    deque<double> d4(d3);                   //通过拷贝一个deque对象的元素值, 创建一个新的deque对象  
    
    //初始化赋值：同vector一样,使用尾部插入函数push_back()  
    for (int i = 1; i < 6 ; i++)  
        d1.push_back(i*10);  
    
    
    //遍历元素: 1-下标方式 2-迭代器方式 反向遍历（略）  
    cout<<"printDeque(d1) : "<<endl;  
    printDeque(d1);  
    
    //元素插入：尾部插入用push_back()，头部插入用push_front()，其它位置插入用insert(&pos, elem)  
    cout<<"d1.push_front(100): "<<endl;  
    d1.push_front(100);  
    printDeque(d1);  
    cout<<"d1.insert(d1.begin()+3, 200): "<<endl; //支持随机存取(即[]操作符)，所以begin()可以+3  
    d1.insert(d1.begin()+2,200);  
    printDeque(d1);  
    
    //元素删除 尾部删除用pop_back();头部删除用pop_front();   
    //任意迭代位置或迭代区间上的元素删除用erase(&pos)/erase(&first, &last)；删除所有元素用clear();  
    cout<<"d1.pop_front(): "<<endl;  
    d1.pop_front();  
    printDeque(d1);  
    
    cout<<"d1.erase(d1.begin()+1): "<<endl;  
    d1.erase(d1.begin()+1); //删除第2个元素d1[1]  
    printDeque(d1);  
    
    cout<<"d1.erase(d1.begin(), d1.begin() + 2) = "<<endl;  
    d1.erase(d1.begin(), d1.begin() + 2);  
    printDeque(d1);  
    
    cout<<"d1.clear() :"<<endl;  
    d1.clear();  
    printDeque(d1);  
    
    system("pause");
    
}  