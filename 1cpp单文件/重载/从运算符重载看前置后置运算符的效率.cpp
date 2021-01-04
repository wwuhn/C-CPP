#include <iostream>
using namespace std;

class Data{
public:
    Data(int num):num(num){}

    Data& operator++(int){  // ºóÖÃ
        Data* result = new Data(this->num++);
        return *result;
    }

    Data& operator++(){     // Ç°ÖÃ
        this->num++;
        return *this;
    }

    void print(){
        cout<<this->num<<endl;
    }
protected:
    int num;
};

int main()
{
    Data data(12);
    Data data2 = data++;
    data2.print();
    data.print();
    data2 = ++data;
    data2.print();
    data.print();

    int a = 12;
    int b = a++;
    int c = ++a;
    while(1);
    return 0;
}
/*
33:       int b = a++;
004015E5   mov         edx,dword ptr [ebp-0Ch]
004015E8   mov         dword ptr [ebp-10h],edx
004015EB   mov         eax,dword ptr [ebp-0Ch]
004015EE   add         eax,1
004015F1   mov         dword ptr [ebp-0Ch],eax
34:       int c = ++a;
004015F4   mov         ecx,dword ptr [ebp-0Ch]
004015F7   add         ecx,1
004015FA   mov         dword ptr [ebp-0Ch],ecx
004015FD   mov         edx,dword ptr [ebp-0Ch]
00401600   mov         dword ptr [ebp-14h],edx

*/