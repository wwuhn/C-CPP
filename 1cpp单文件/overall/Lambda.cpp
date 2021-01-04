#include <iostream>
#include <functional>
using namespace std;

void foo(int a)
{
    double b=a*2;
    auto c=[b](int d)->char{
        char e=static_cast<char>(d+b);
        return e;
    }(a/2);
    cout<<c<<endl; 
}

void foo2(int a)
{
    double b=a*2;
    auto c=[&b](int d)->char{
        b++;
        char e=static_cast<char>(d+b);
        return e;
    }(a/2);
    cout<<c<<endl;
}

void foo3(int a){
	function <void(void)> f;
	//{	// ���ⶨ��һ���ֲ������
		a++;
		std::string s="abc";
		f=[a,&s]{
			cout<<a<<endl;
			s+="de";
			cout<<s<<endl;
		};
	//}
	f();
}

void foo4()
{
    int a=3, b=4;
    [a,&b]()mutable{
        a=30;//�����޸ģ�a������read-only,��Ϊ��mutable����
        b=40;
    }();
    cout<<a<<endl; //3
    cout<<b<<endl; //40
}

int main()
{
	
	[]{cout<<"Lambda expression!"<<endl;};
	[]{cout<<"Lambda expression!"<<endl;}();
	auto f=[](int a,int b){return a>b;};

	cout<<f(4,3)<<endl; //1
    function<bool(int, int)> ff= f;
    cout<<ff(6,5)<<endl;//1

	int c=[](int a, int b)
	{
		return a+b;
	}(3,4);
	cout<<c<<endl;//7

	double d = [](int a, double b)->double
	{
		return a/b;
	}(3,4);
	cout<<d<<endl;//0.75

	foo(20);//2��2��ASCII��50
	foo2(20);//3��2��ASCII��51
	foo3(3);
	foo4();
	bool(*fp)(int, int)=[](int a,int b){return a>b;};//������ʱ�ſ�ת��Ϊ����ָ��
	return 0;
}
/*
Lambda expression!                                                                                                      
1                                                                                                                       
1                                                                                                                       
7                                                                                                                       
0.75                                                                                                                    
2                                                                                                                       
3                                                                                                                       
4                                                                                                                       
abcde                                                                                                                   
3                                                                                                                       
40   
*/