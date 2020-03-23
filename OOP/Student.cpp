#include<iostream>
using namespace std;
class Student{
	int age;
	char *name; 
public:
	Student(int age, char *name){
		this->age=age;
		/*
		this->name=name;
		*/
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);
	}
	void display(){
		cout<<name<<" "<<age<<endl;
	}
};