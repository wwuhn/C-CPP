#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>
using namespace std;
bool MatchFirstChar(const string &str) { return 'S' == str[0];} //ν�ʺ���
int main(){
	const int VECTOR_SIZE=8;
	string names[]={"She","Sells","Sea","Shells","by","the","Sea","Shores"};
	//���������ַ�����������������
	vector<string>NamesVect(names,names+VECTOR_SIZE);
	//�������������[start,end)������һ�����ұ�����
	vector<string>::iterator start,end;
	start=NamesVect.begin();
	end=NamesVect.end();
	//���õ�������[start,end)������������������������Ԫ��
	cout<<"NamesVect{";
	for(vector<string>::iterator it=start;it !=end; it++)
		cout<<*it<<" ";
	cout<<"}\n"<<endl;
	//����count_if��������������ʹ��MatchFirstChar);		
	int result = count_if(start,end,MatchFirstChar);		//������'s'��ͷ���ַ���
	cout<<"����="<<result<<endl;
	getch();
	return 0;
}