#if 0

#include <stdio.h>
#include <stdlib.h>
//#include <time.h> //for sleep() function
#include<windows.h>
#include <winbase.h>

int main()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
	int hour = time.wHour;
	int minute = time.wMinute;
	int second = time.wSecond;

	while(1)
	{
		system("cls");//clear output screen
		printf("%02d : %02d : %02d ",hour,minute,second);//print time in HH : MM : SS format
		fflush(stdout);//clear output buffer in gcc
		second++; //increase second
		if(second==60){//update hour, minute and second
			minute+=1;
			second=0;
		}
		if(minute==60){
			hour+=1;
			minute=0;
		}
		if(hour==24){
			hour=0;
			minute=0;
			second=0;
		}
		Sleep(1000); //wait till 1 second
	}
	
	system("pause");
	return 0;
}

#else

#include <stdlib.h>
#include <iostream>
using namespace std;
#include<windows.h>
#include <winbase.h>
// 第一部分
class Clock
{
public:                                                                              
	void SetTime(int NewH,int NewM,int NewS);       
	void ShowTime();
	Clock operator++();
	Clock operator++(int);
private:                                                              
	int  Hour,Minute,Second; 
};

// 第二部分
void Clock::SetTime(int NewH, int NewM, int NewS)
{
	Hour=NewH;
	Minute=NewM;
	Second=NewS;
}
void Clock::ShowTime()
{
    
    // cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
    system("cls");//clear output screen
    printf("%02d : %02d : %02d \n\n\n",Hour,Minute,Second);//print time in HH : MM : SS format
    fflush(stdout);//clear output buffer in gcc
    
    
    Sleep(1000); //wait till 1 second
    
} 
// 第三部分

void main()
{
	Clock  myClock;
	//myClock.SetTime(8,30,30);
	//++myClock;
	//myClock++;

    SYSTEMTIME time;
    GetLocalTime(&time);
	int hour = time.wHour;
	int minute = time.wMinute;
	int second = time.wSecond;
    myClock.SetTime(hour,minute,second);
    while(1)
    {
        myClock.ShowTime();
        myClock++;
    }
	myClock.ShowTime();
	
    system("pause");

}
Clock Clock::operator++()
{
	++Second;
	if(Second>=60)
	{
		Second=Second-60;
		++Minute;
		if(Minute>=60)
		{
			Minute=Minute-60;
			++Hour;
			Hour=Hour%24;
		}
	}
	return *this;
}
Clock Clock::operator++(int)
{
	Clock old=*this;
	++(*this);
	return *this;
}

#endif