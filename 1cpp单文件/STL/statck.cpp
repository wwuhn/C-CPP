#include <iostream>  
#include <Stack>  
using namespace std;  
  
void main()  
{  
    stack<double> s;//�����Ǹ����������ͣ�  
    for( int i=0; i < 10; i++ )  
        s.push(i);  
    while(!s.empty())  
    {  
        printf("%lf\n",s.top());  
        s.pop();  
    }  
    cout << "the size of  s: " << s.size() << endl;  
	system("pause");
}  