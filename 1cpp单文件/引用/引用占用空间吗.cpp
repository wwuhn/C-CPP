#include <iostream>
using namespace std;
void fa(){
    int a[4];    
    cout<<a<<endl;
}
void fb4(){
    int a[4];
    //int &b=a[0];// ��ע�͵��˾�ʱ��������fa()��a[]�ĵ�ַ�ı仯��
    cout<<a<<endl;
	
    fa();
}
void fb3(){
    int a[4];
    int b=20;
    cout<<a[-1]<<endl; //���20

    fa();
}
void fb(){
    int a[4]={1,2,3,4};
    int& b=a[0];
	cout<<a[-1]<<endl;//���1244796
    a[-1]+=12;//�ƶ���12���ֽ�
	// bָ����a[3];
    cout<<b<<","<<a[0]<<endl;//���1244808
	// bֱ�ӽ����ã�ָ��Ľ�������ʹ�÷���*��
	cout<<a[-1]<<endl;//���4,1
    fa();
}
void fc(){
    int a[4];
    cout<<a<<endl;
    fb();
}
int main()
{
    fc();
    getchar();
    return 0;
}
/*���int &b=a[0];��ע��ʱ�������
0012FEE0 //fc()��a[]�ĵ�ַ
0012FE7C //fb()��a[]�ĵ�ַ
0012FE18 //fa()��a[]�ĵ�ַ
���int &b=a[0];δ��ע��ʱ�������
0012FEE0
0012FE7C
0012FE14
*/