#include<bits/stdc++.h>
using namespace std;
class Student{
public:
	int rollNum;
	int age;
	static int totalStudents;
	Student(){
		totalStudents++;
	}
};
int Student::totalStudents=0;

int main(){
	Student s1;
	s1.age=24;s1.rollNum=101;
	cout<<s1.age<<" "<<s1.rollNum<<" "<<Student::totalStudents<<endl;
	Student s2,s3,s4,s5,s6,s7,s8;
	cout<<Student::totalStudents<<endl;
	return 0;
}


// class Student {
//     public :

//     int rollNumber;

//     static int getRollNumber() {
//         return rollNumber;
//error: invalid use of member ‘Student::rollNumber’ in static member function

//     }
// };


// int main() {
//     Student s;
//     s.rollNumber = 101;
//     cout << s.getRollNumber() << endl;
// }