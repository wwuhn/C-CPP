#include <iostream>

template <class type>
type sum(type xvar,type yvar)
{
	return xvar + yvar;
}

template <class type>
type sum(type arr[],int len)
{
	type ret = 0;
	for(int i=0;i<len;i++)
	{
		ret += arr[i];
	}
	return ret;
}

int main()
{
	int iret = sum(10,20);
	printf("����֮�ͣ�%d\n",iret);
	int arr[5] = {1,2,3,4,5};
	int ret = sum(arr,5);
	printf("����Ԫ��֮�ͣ�%d\n",ret);
	system("pause");
	return 0;
}