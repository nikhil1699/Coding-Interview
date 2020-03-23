#include<bits/stdc++.h>
#include "Student.cpp"
using namespace std;
int main(){
  char name[]="abcd";
  Student s1(20, name);
  s1.display();
  name[3]='e';
  Student s2(24,name);
  s2.display();
  s1.display();// s1 name was abcd now it is abce as we changed the name.



  return 0;
}