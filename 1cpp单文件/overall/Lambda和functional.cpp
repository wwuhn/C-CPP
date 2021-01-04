#include <iostream>
#include <memory>
#include <functional>
using namespace std;

int main()
{
	[]{
		cout<<"Lambda!"<<endl;
	};

	[]{
		cout<<"Lambda ()!"<<endl;
	}();

	auto f = []{
		cout<<"Lambda f()!"<<endl;
	};	
	f();

	auto f1 = []{
		cout<<"Lambda 1!"<<endl;
	};

	auto f2 = []{
		cout<<"Lambda 2!"<<endl;
	};

	auto f3 = []{
		cout<<"Lambda 3!"<<endl;
	};

    function<void(void)> F[3] = {f1,f2,f3};
    for(int i=0; i<3; ++i)
        F[i]();

	cout<<[](int a, int b){ return a+b; }(3,4)<<endl;
	auto ff=[](int n){ return n*n; };
	cout<<ff(3)<<endl;
    system("pause");
	return 0;
}
/*
Lambda ()!                                                                                                            
Lambda f()!                                                                                                           
Lambda 1!                                                                                                             
Lambda 2!                                                                                                             
Lambda 3!
7
9
 */