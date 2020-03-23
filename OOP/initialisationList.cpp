#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
		int age;
		const int rollNumber;
		Student(int r):rollNumber(r){

		}
		void display(){
			cout<<"Roll Number: "<<rollNumber<<" Age: "<<age<<endl;
		}
};
int main(){
	Student s1(23);
	s1.age=44;
	s1.display();
	return 0;
}
