#include <iostream>
#include <memory> 
using namespace std;

class Employee {
public:
	Employee(string theName) : name(theName){};
	string getName() const {return name;}
	virtual void print() const {
		cout << "Employee: " << getName() << endl;
	}
private:
	string name;
};

class Manager : public Employee {
public:
	Manager(string theName, Employee theEmployee) :
	    Employee(theName), assistant(theEmployee) {};
        
	Employee getAssistant() const {return assistant;}
	virtual void print() const {
		cout << "Manager: " << getName() << endl;
		cout << "Assistant: " << assistant.getName() << endl;
	}
private:
	Employee assistant;
};

int main () {
	Employee coder("Joe Smith");
	Employee typist("Bill Jones");
	Manager designer("Jane Doe", typist);
	
	coder = designer; //������:�з��˶���designer:Jane Doe
	coder.print();  // Employee: Jane Doe
	
	// ʹ�����ñ�������з�
	Employee &rcoder = designer; // Jane remains entire
	rcoder.print();
    /*�����
    Manager: Jane Doe                                                                                                     
    Assistant: Bill Jones  
    */
	
	// ʹ��ָ���������з�
	Employee *pcoder = new Employee("Joe Smith");
	Employee *ptypist = new Employee("Bill Jones");
	Manager *pdesigner = new Manager("Jane Doe", *ptypist);
	pcoder = pdesigner;
	pcoder->print(); //���ͬ��
	
	// ʹ������ָ���������з�
	unique_ptr<Employee> scoder=make_unique<Employee>("Joe Smith");
	unique_ptr<Employee> stypist=make_unique<Employee>("Bill Jones");
	unique_ptr<Manager> sdesigner=make_unique<Manager>("Jane Doe", *stypist);
	scoder=move(sdesigner); // Smith deleted, Doe xferred
	scoder->print(); //���ͬ��

}
