#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


int solve(double a,double b,double c,double *x1,double*x2);
double bac(double a ,double b,double c);
double root(double a,double b,double c);

double bac(double a ,double b,double c)
{
	return b*b - 4*a*c;
}

double root(double a,double b,double c)
{
	double n;
	n=bac(a,b,c);
	if(n<0)
		return -1;
	else
		return sqrt(n);
}

int solve(double a,double b,double c,double *x1,double*x2)
{
	double r = root(a,b,c);
	if(r == -1)
		return -1; //方程无实数解
	else if(r ==0)
    {
        *x1 = *x2 = -1*b/2*a;
        return 1; // 方程有一个实数解
    }
	else
	{
		*x1 =(-1*b+r)/(2*a);
		*x2 =(-1*b-r)/(2*a);
		return 2; // 方程有2个实数解
	}
}
double equation(double a1,double a2,double x)
{
    return x*(a1-2*x)*(a2-2*x);
}

double bfMax(double a1,double a2)
{
    double x = 1;
    double best = x;
    double max = 1;
    FILE* fp;
    fp = fopen("result.txt","w+");
    char line[128] = {0};
    sprintf(line,"%s\t%s\t\t%s\t%s\n","x","value","best","max");
    fputs(line,fp);
    while(x<a2/2)
    {
        double value = equation(a1,a2,x);
        sprintf(line,"%5.2f\t %9.2f\t %5.2f\t %9.2f\n",x,value,best,max);
        fputs(line,fp);
        if(max<value)
        {
            max = value;
            best = x;
        }
        x += 0.01;
    }
    fclose(fp);
    //GetModuleFileName(NULL, line, 128);
    //printf("%s\n",line);
    system("result.txt");
    return best;
}

int main()
{
	double a1 = 297;
    double a2 = 210;
    double a = 12;
    double b = -4*(a1+a2);
    double c = a1*a2;
    double x1,x2;

    printf("一张A4纸大小的铁皮，做成一个无盖的长方形盒子，\n");
	printf("怎样截角可能做到盒子容积最大?\n");
	printf("体积方程：f(x)=x(a-2x)(b-2x)\n");
    printf("A4 paper size:length*width=297*210\n");
    printf("f(x)=4x^3-2(a+b)x^2+abx\n");

    printf("f'(x)=12x^2-4(a+b)x+ab\n");
	printf("体积方程求导，当导数等于0时，可求得最大值；\n");     
    int i = solve(a,b,c,&x1,&x2);
    if(i == -1)
        printf("无实数解！\n");
    if(i == 1)
        printf("有一个实数解：%lg\n",x1);
    if(i == 2)
        printf("有2个实数解：%lg,%lg\n",x1,x2);
    printf("截去的长度需满足：x>0 && (210 - 2*x)>0\n");
    if(x1>0 && (210 - 2*x1)>0)
	    printf("截去的长度可以是：%f\n",x1);
    if(x2>0 && (210 - 2*x2)>0)
	    printf("截去的长度可以是：%f\n",x2);
    printf("枚举的结果：%lg\n",bfMax(a1,a2));

	system("pause");
	return 0;
}
/*
一张A4纸大小的铁皮，做成一个无盖的长方形盒子，
怎样截角可能做到盒子容积最大?
体积方程：f(x)=x(a-2x)(b-2x)
A4 paper size:length*width=297*210
f(x)=4x^3-2(a+b)x^2+abx
f'(x)=12x^2-4(a+b)x+ab
体积方程求导，当导数等于0时，可求得最大值；
有2个实数解：128.577,40.4234
截去的长度需满足：x>0 && (210 - 2*x)>0
截去的长度可以是：40.423362
枚举的结果：40.42
*/
