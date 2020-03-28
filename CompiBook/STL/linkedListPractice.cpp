#include<bits/stdc++.h>
using namespace std;

void showList(list<int> l){
    list<int>::iterator it;
    for(it=l.begin();it != l.end();++it){
        cout<<"\t"<<*it;
    }
    cout<<"\n";
}


int main(){
    list<int> list1;
    cout<<"Enter initial number of elements: "<<"\n";
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        list1.push_back(element);
    }
    showList(list1);

    cout<<list1.front()<<endl;
    cout<<list1.back()<<endl;
    cout<<"****************"<<endl;
    list1.pop_back();
    list1.reverse();
    
    cout<<list1.size()<<endl;
    list1.push_front(99);
    list1.push_back(2);
    cout<<endl;
    showList(list1);
    cout<<endl;
    list<int>:: iterator it=list1.begin();
    advance(it,2);
    list1.insert(it,71);
    cout<<endl;
    showList(list1);


    return 0;
}