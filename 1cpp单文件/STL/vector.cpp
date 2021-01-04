#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int a[]={1,3,4,6,8,7};
    vector<int> arr(a,a+6);
    vector<int> ::iterator begin;
    /*Initialize a vector*/
    cout<<"Initialize vector arr with a:"<<endl;
    for(begin=arr.begin();begin!=arr.end();begin++)
        cout<<*begin<<" ";
    cout<<endl;

    /*Sort the vector*/ 
    cout<<"After arr was sorted:"<<endl;
    sort(arr.begin(),arr.end());
    for(begin=arr.begin();begin!=arr.end();begin++)
        cout<<*begin<<" ";
    cout<<endl;

    /*pop*/
    arr.pop_back();
    cout<<"After pop_back:"<<endl;
    for(begin=arr.begin();begin!=arr.end();begin++)
        cout<<*begin<<" ";
    cout<<endl;

    /*push*/
    arr.push_back(8);
    cout<<"After push_back:"<<endl;
    for(begin=arr.begin();begin!=arr.end();begin++)
        cout<<*begin<<" ";
    cout<<endl;

    /*search*/
    const int FINDNUMBER=4;
    cout<<"Find the element which value is 4:"<<endl;
    vector<int> ::iterator search=find(arr.begin(),arr.end(),FINDNUMBER);
    if(search!=arr.end())
        cout<<"Find"<<" "<<*search<<" "<<"SUCCESS"<<endl;
    else
        cout<<"FAILED"<<endl;


    /*clear*/
    cout<<"Destroy the vector"<<endl;
    arr.clear();
	system("pause");
}
/*
Initialize vector arr with a:
1 3 4 6 8 7
After arr was sorted:
1 3 4 6 7 8
After pop_back:
1 3 4 6 7
After push_back:
1 3 4 6 7 8
Find the element which value is 4:
Find 4 SUCCESS
Destroy the vector
*/