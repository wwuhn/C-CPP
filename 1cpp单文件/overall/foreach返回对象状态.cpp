#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>&v)
{
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}

class meanv
{
	long num;
	long sum;
public:
	meanv():num(0),sum(0){}

	void operator()(int elem)
	{
		num++;
		sum+=elem;
	}
    
	double value()
	{
		return static_cast<double>(sum*1.0/num);
	}
};

int main()
{
	vector<int> vc;
	int arr[6]={1,2,3,4,5,6};
	vc.assign(arr,arr+6);
	print(vc);

	meanv mv=for_each(vc.begin(),vc.end(),meanv());
	cout<<"Mean value: "<<mv.value()<<endl;
    cin.get();
	return 0;
}
/*
1 2 3 4 5 6
Mean value: 3.5
*/