#include <iostream.h>


class Worker{
public:
	int m_salary;
	Worker():m_salary(0){}
	Worker(int i):m_salary(i){}
	Worker(const Worker& other){
		m_salary = other.m_salary;
	}
	friend Worker operator+(const Worker& w1,const Worker& w2);
	Worker& operator+=(const Worker& w){
		m_salary+=w.m_salary;
		return *this;
	}
};

Worker operator+(const Worker& w1,const Worker& w2){
	return Worker(w1.m_salary+w2.m_salary);
}

int main()
{
	Worker w1(3000);
	Worker w2(w1);
	Worker w3 = operator+(w1,w2);
	w3 = w1+w2;
	cout<<w3.m_salary<<endl;
	w3+=w1;
	cout<<w3.m_salary<<endl;

	return 0;
}
