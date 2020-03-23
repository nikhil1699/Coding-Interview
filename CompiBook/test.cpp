#include<bits/stdc++.h>
using namespace std;
void showList(list<int> g1){
    list<int>:: iterator it;
    for (it=g1.begin();it != g1.end();++it)
    {
        cout<<*it<<"\n";
    }
    
}

int main(){
    list<int> gqlist;



    for(int i=0;i<10;i++){
        gqlist.push_back(i);
       
    }
     showList(gqlist);
     gqlist.push_front(100);
     showList(gqlist);
     return 0;
}