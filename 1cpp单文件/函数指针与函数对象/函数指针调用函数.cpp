#include <iostream>
using namespace std;

void pass(int score){cout<<"score:"<<score<<",passed!"<<endl;}
void fail(int score){cout<<"score:"<<score<<",not passed!"<<endl;}
void excell(int score){cout<<"score:"<<score<<",excellent!"<<endl;}

void main()
{
	int score = 0;
	do{
		cout<<"请输入一个分数(－1时结束)：";
		cin>>score;
		void (*pfunc)(int);
		if(score<60) pfunc = fail;
		else if(score>=60 && score<90) pfunc = pass;
		else pfunc = excell;
		(*pfunc)(score);
	}while(score != -1);
}