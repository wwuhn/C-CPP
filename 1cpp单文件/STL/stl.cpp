#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>
using namespace std;
bool MatchFirstChar(const string &str) { return 'S' == str[0];} //谓词函数
int main(){
	const int VECTOR_SIZE=8;
	string names[]={"She","Sells","Sea","Shells","by","the","Sea","Shores"};
	//产生容纳字符串的向量容器对象
	vector<string>NamesVect(names,names+VECTOR_SIZE);
	//定义迭代器对象，[start,end)定义了一个左开右闭区间
	vector<string>::iterator start,end;
	start=NamesVect.begin();
	end=NamesVect.end();
	//利用迭代器在[start,end)区间遍历向量容器，输出容器元素
	cout<<"NamesVect{";
	for(vector<string>::iterator it=start;it !=end; it++)
		cout<<*it<<" ";
	cout<<"}\n"<<endl;
	//调用count_if计数向量容器中使用MatchFirstChar);		
	int result = count_if(start,end,MatchFirstChar);		//计算以's'开头的字符串
	cout<<"个数="<<result<<endl;
	getch();
	return 0;
}