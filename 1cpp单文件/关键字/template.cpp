#include <stdio.h>
#include <stdlib.h>

template<typename T>
T max(const T arr[], int size) {
	T maxElem=arr[0];
	for (int i=0;i<size;i++)
		if(arr[i]>maxElem) 
            maxElem=arr[i];
    return maxElem;
}

int main(){
	int a[] = {1,2,4,8,7};
	int b = max(a,sizeof(a)/sizeof(int));
	printf("�������Ԫ�أ�%d",b);
	system("pause");
	return 0;
}
//�������Ԫ�أ�8
//����ģ��Ҳ����ʾʵ������template int max<int>(const int[],int);