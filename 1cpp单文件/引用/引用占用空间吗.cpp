#include <iostream>
using namespace std;
void fa(){
    int a[4];    
    cout<<a<<endl;
}
void fb4(){
    int a[4];
    //int &b=a[0];// 当注释掉此句时，会引起fa()中a[]的地址的变化；
    cout<<a<<endl;
	
    fa();
}
void fb3(){
    int a[4];
    int b=20;
    cout<<a[-1]<<endl; //输出20

    fa();
}
void fb(){
    int a[4]={1,2,3,4};
    int& b=a[0];
	cout<<a[-1]<<endl;//输出1244796
    a[-1]+=12;//移动了12个字节
	// b指向了a[3];
    cout<<b<<","<<a[0]<<endl;//输出1244808
	// b直接解引用（指针的解引用需使用符号*）
	cout<<a[-1]<<endl;//输出4,1
    fa();
}
void fc(){
    int a[4];
    cout<<a<<endl;
    fb();
}
int main()
{
    fc();
    getchar();
    return 0;
}
/*语句int &b=a[0];被注释时的输出：
0012FEE0 //fc()的a[]的地址
0012FE7C //fb()的a[]的地址
0012FE18 //fa()的a[]的地址
语句int &b=a[0];未被注释时的输出：
0012FEE0
0012FE7C
0012FE14
*/