#include<iostream>
using namespace std;

class Counter {
	int value;								// ��������ֵ
	int alarm;								// ����ֵ
public:
	Counter(int a) {value = 0; alarm = a;}

	Counter & operator++();					// ǰ׺��++����
	Counter operator++(int);				// ��׺��++����

	void print() {cout << value << endl; }
}; 

Counter & Counter::operator++()
{ 
    if (value == alarm) 
        cout << "�ѳ�������ֵ\n";
    else 
	{ 
        ++value;
        if (value == alarm) 
            cout << "�ѵ��ﱨ��ֵ\n";
    }
    return *this;
}

Counter Counter::operator++(int x)
{ 
    Counter tmp = *this;						// ��������޸�ǰ��״̬
    if (value == alarm) 
        cout << "�ѳ�������ֵ\n";
    else 
    { 
        ++value;
        if (value == alarm) 
            cout << "�ѵ��ﱨ��ֵ\n";
    }
    return tmp;									// �����޸�ǰ��״̬
}

int main()
{
	Counter cnt(3);		// ����һ��Counter��Ķ��󣬱���ֵΪ3
	cnt.print();		// ��ʾ����ĵ�ǰֵ����ʱ���Ϊ0
	++cnt;
	cnt.print();		// ��ʱ���Ϊ1
	(++cnt).print();	// ����ǰ׺��++�����2
	(cnt++).print();	// ���ú�׺��++����ǰ�����value�Ѿ�
						// ��1�����������������2
	cnt.print();		// ���ֵΪ3
	system("pause");
	return 0;
}
/*
0
1
2
�ѵ��ﱨ��ֵ
2
3
*/
