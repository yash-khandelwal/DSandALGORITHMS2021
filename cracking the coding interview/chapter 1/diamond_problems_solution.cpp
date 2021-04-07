#include<iostream>
using namespace std;
class Person {
public:
	Person(int x) { cout << "constructor Person::Person(int ) called" << endl; }
	Person()	 { cout << "constructor Person::Person() called" << endl; }
	~Person()	 { cout << "destructor Person::Person() called" << endl; }
	// as the function below is a pure virtual function therefore Person is an abstract class and it cannot be instantiated.
	// this class also known as interface
	virtual void type() = 0;
};

class Faculty : virtual public Person {
public:
	Faculty(int x):Person(x) {
	cout<<"constructor Faculty::Faculty(int ) called"<< endl;
	}
	~Faculty()	 { cout << "destructor Faculty::Faculty() called" << endl; }
	void type(){cout<<"Faculty\n";}
};

class Student : virtual public Person {
public:
	Student(int x):Person(x) {
		cout<<"constructor Student::Student(int ) called"<< endl;
	}
	~Student()	 { cout << "destructor Student::Student() called" << endl; }
};

class TA : public Faculty, public Student {
public:
	TA(int x):Student(x), Faculty(x) {
		cout<<"constructor TA::TA(int ) called"<< endl;
	}
	~TA()	 { cout << "destructor TA::TA() called" << endl; }
};

int main() {
	TA ta1(30);
	ta1.type();
	// cant declare abstract type variable p;
	// Person p;
}
