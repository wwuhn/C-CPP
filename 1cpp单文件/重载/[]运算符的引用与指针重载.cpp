#include <iostream.h>
#include <assert.h>
#include <stdlib.h>
//#define ANOTHER
// using namespace std;
class vector
{
	int* data;
	int size;
public:
	vector()
	{
		data=NULL;
		size=0;
	}

	vector(int* pData,int n){
		data = pData;
		size = n;
	}

	~vector()
	{
		delete[] data;
	}

	int setSize(int n)
	{
		delete[] data;
		data = new int[n];
		size = n;
		return size;
	}

	int getSize() const
	{
		return size;
	}

	friend ostream& operator<<(ostream& of, vector& v);
    friend ostream* operator<<(ostream* of, vector v);

#ifdef ANOTHER
	int* operator[](int n)
	{
		assert(n>=0 && n<size);
		return data+n;
	}
#else
	int& operator[](int n)
	{
		assert(n>=0 && n<size);
		return data[n];
	}
#endif

};


#ifdef ANOTHER

ostream* operator<<(ostream* of, vector v) // 能编译通过，但不能连接
{
	(*of)<<v.size<<": "<<'\n';
	for(int i=0;i<v.size;i++)
		(*of)<<v[i]<<" "<<endl;
	return of;
}
#else
ostream& operator<<(ostream& of, vector& v)
{
	of<<v.size<<": "<<'\n';
	for(int i=0;i<v.size;i++)
		of<<v[i]<<" "<<endl;
	return of;
}
#endif

int main()
{
	int i;
	vector v;
	int size = 10;
	v.setSize(size);

#ifdef ANOTHER
	for(i=0;i<size;i++)
		*v[i]=i;
	*v[5]=555;
	for(i=0;i<size;i++)
		cout<<*v[i]<<endl;
#else
	for(i=0;i<size;i++)
		v[i]=i;
	v[5]=5555;
	for(i=0;i<size;i++)
		cout<<v[i]<<endl;
#endif


	int arr[4]={1,2,3,4};
	vector vTest(arr,4);

	cout<<vTest;
    system("pause");
	return 0;


}