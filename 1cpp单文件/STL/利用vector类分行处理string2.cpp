#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<string> split(string str, char del) {
	stringstream ss(str);
	string temp;
	vector<string> ret;
	while (getline(ss, temp, del)) {
		ret.push_back(temp);
	}
	return ret;
}

int main()
{
    string str  = "������ˮ��\nˮ���������������\n";
		   str += "������֮���񣬹ʼ��ڵ���\n";
	 
    vector<string> vec = split(str,'\n');

	vector<string>::iterator vit=vec.begin();
    for(;vit!=vec.end();vit++)
    {
        printf("%s\n", (*vit).c_str());
    } 
    cin.get();
	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
	cin.ignore(32767, '\n'); ignore up to 32767 characters until a \n is removed
	system("pause");
	getchar();
*/