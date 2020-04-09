#include <bits/stdc++.h>
using namespace std;


class Student{
    public:
    string name;
    int marks;
    int rollNo;
};


bool compare(Student* S1, Student* S2){
    if(S1->marks != S2->marks){
        return S1->marks > S2->marks;
    }
    return S1->rollNo < S2->rollNo;
}
int main()
{
    int n;
    cin>>n;
    Student** students=new Student*[n];
    for(int i=0;i<n;i++){
        students[i]=new Student();
    }
   for (int i = 0; i < n; i++)
   {
       /* A loop to get details of all students one by one */
       cin>>students[i]->name;
       students[i]->rollNo=i+1;
       int m1,m2,m3;
       cin>>m1>>m2>>m3;
       int total=m1+m2+m3;
       students[i]->marks=total;
   }

    sort(students,students+n,compare);
    for(int i=0;i<n;i++){
        cout<<(i+1)<<" "<<students[i]->name<<endl;
    }
   
     
    
    
    return 0;
}
