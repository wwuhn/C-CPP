#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool evenNum( int n ) //是否为偶数
{ return n % 2; }

void main()
{
	int num = 6;
	vector<int> v1;
	for( int i = 0; i != 10; ++i )
		v1.push_back(i);

	vector<int>::iterator iter = find( v1.begin(), v1.end(), num ); //查找等于6的元素位置
	if( iter != v1.end() )
		cout << "匹配元素的索引: " << iter - v1.begin() << endl; //找到匹配元素位置6

	vector<int> v2;
	v2.push_back(6);
	v2.push_back(5);
	v2.push_back(3);
	iter = find_first_of( v1.begin(), v1.end(), v2.begin(), v2.end() ); //第一个匹配元素是3
	if( iter != v1.end() )
		cout << "第一个匹配元素索引：" << iter - v1.begin() << endl;

	int even_times = count_if( v1.begin(), v1.end(), evenNum ); //谓词函数参数，偶数个数为5个
	cout << "偶数个数 ：" << even_times << endl;
	cin.get();
}
/*
匹配元素的索引: 6
第一个匹配元素索引：3
偶数个数 ：5
*/




































