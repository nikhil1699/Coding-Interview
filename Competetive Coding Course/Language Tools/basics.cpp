#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
};
bool compare(Interval i1, Interval i2){
    return i1.start<i2.start;
}
cout<<__gcd(12,43);
cout<<pow(2,3);
int x=3;int y=5;
swap(x,y);
int main()
{

    vector<int> v(5); // Create a array of 5 elements
    // Iterator is a pointer to an element within range of elements
    vector<int> :: iterator it;
    Interval arr[]={{6,4},{3,2},{4,6},{8,13}};
    sort(arr,arr+4,compare);
    for(it=v.begin(); it!=v.end(); it++){
        v.push_back(4);
    cout<< *it<<endl; 
    }//v.end() pointe to next of last element
    
    sort(v.begin(),v.end(),greater<int>());// Rzeverse sort
    string s1="Nikhil";
    string s2(s1,2,4);
    string s3=s1.substr(1,4); //4 characters from 1
    bool x= s1.compare(s2);

    pair <int,char> p;
    p=make_pair(2,'b');
    pair<int,char> p1(1,'a');
    cout<<p1.first<<p1.second;

    //Set remains sorted
    //unordered_set is Unsorted
    set<int> s; // Using Balanced Binary Seach Tree so all operations log(h)
    int arr[]={1,2,3,4,5,4,3,6,1};

    for(int i=0;i<9;i++){
        s.insert(arr[i]);
    }
    set<int>:: iterator it2;
    for(it2=s.begin();it2 !=s.end();it2++){
        cout<<*it;
    }
    if(s.find(6)== s.end()){
        cout<<"Not found";
    }else{
        cout<<"found";
    }

    // Map
    int arr2[]={1,2,3,4,5,3,2,4,5,6};
    map<int,int> m;
    for(int i=0;i<arr2.size();i++){
        m[arr[i]]++;
    }    
    map<int,int>:: iterator it3;
    for (it3=m.begin();it3!=m.end();it3++){
        cout<<it3->first<<":"<<it3->second<<endl;
    }
    
    binary_search(v.begin(),v.end(),5);// Returns if the element is there or not
    cout<<lower_bound(v.begin(),v.end(),2)-v;



    
    return 0;
}
