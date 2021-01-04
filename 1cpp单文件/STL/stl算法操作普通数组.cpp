// stl算法操作普通数组
#include <iostream>
#include <algorithm>

int main()
{
	int col[]={1,5,7,2,8};
	std::sort(col,col+5);
	std::copy(col,col+5,std::ostream_iterator<int>(std::cout," "));
	std::cin.get();
	return 0;
}
