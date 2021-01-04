#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(void){
    /*Initialize Linklist*/
    int arr[]={3,8,9,4,6,2,4,8};
    list<int> Linklist(arr,arr+8);
    list<int> ::iterator pmove; 

    /*isEmpty?*/ 
    if(Linklist.empty())
        cout<<"Linklist is empty"<<endl;
    else
        cout<<"Linklist is not empty"<<endl;

    /*Traverse*/
    cout<<"Traverse Linklist"<<endl;
    for(pmove=Linklist.begin();pmove!=Linklist.end();pmove++)
        cout<<*pmove<<" ";
    cout<<endl; 

    /*push_back*/
    cout<<"Push_back 5"<<endl;
    Linklist.push_back(5);
    for(pmove=Linklist.begin();pmove!=Linklist.end();pmove++)
        cout<<*pmove<<" ";
    cout<<endl; 

    /*find push_front  pop_front and pop_back is same with oush_back operation, I dont wanna repeat*/

    /*count*/
    cout<<"Count"<<endl;
    int Count=count(Linklist.begin(),Linklist.end(),4);
    cout<<Count;

	system("pause");
}
/*
Linklist is not empty
Traverse Linklist
3 8 9 4 6 2 4 8
Push_back 5
3 8 9 4 6 2 4 8 5
Count
2*/