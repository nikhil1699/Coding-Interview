#include<bits/stdc++.h>
using namespace std;
int main(){
	
// structure set is implemented via balanced binary tree and most of the operations are log(n)	
// structure unordered_set is implemented via a hashing and its operations are o(1) average
// set maintains sorted order

	set<int> s;
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1
	cout << s.count(4) << "\n"; // 0
	s.erase(3);
	s.insert(4);
	cout << s.count(3) << "\n"; // 0
	cout << s.count(4) << "\n"; // 1
	cout<<"************************"<<"\n";
	//The following code creates a set, prints the
	//number of elements in it, and then iterates through all the elements:
	set<int> s1={2,5,5,4,6,7,8,1,9};
	cout<<s1.size()<<"\n";
	for(auto x: s1){
		cout<<x<<"\n";
	}
	cout<<"**************************"<<"\n";

	unordered_set<int> s3={1,4,2,5,5,6,4,3,5,6,7,8};
	cout<<s3.size()<<"\n";
	for(auto x: s3){
		cout<<x<<"\n";
	}
	// declaring set for storing string data-type 
    unordered_set <string> stringSet ; 
  
    // inserting various string, same string will be stored 
    // once in set 
  
    stringSet.insert("code") ; 
    stringSet.insert("in") ; 
    stringSet.insert("c++") ; 
    stringSet.insert("is") ; 
    stringSet.insert("fast") ; 
  
    string key = "slow" ; 
  
    //  find returns end iterator if key is not found, 
    //  else it returns iterator to that key 
  
    if (stringSet.find(key) == stringSet.end()) 
        cout << key << " not found" << endl << endl ; 

    else
        cout << "Found " << key << endl << endl ; 
  
    key = "c++"; 
    if (stringSet.find(key) == stringSet.end()) 
        cout << key << " not found\n" ; 
    else
        cout << "Found " << key << endl ; 
  
    // now iterating over whole set and printing its 
    // content 
    // unordered_set<string> :: iterator itr; 
    // for (itr = stringSet.begin(); itr != stringSet.end(); itr++){
    //     cout << (*itr) << endl; 
    // }

    /*
	void printDuplicates(int arr[], int n) 
	{ 
	    // declaring unordered sets for checking and storing duplicates

	    unordered_set<int> intSet; 
	    unordered_set<int> duplicate; 
	  
	    // looping through array elements 
	    for (int i = 0; i < n; i++) 
	    { 
	        // if element is not there then insert that 
	        if (intSet.find(arr[i]) == intSet.end()) 
	            intSet.insert(arr[i]); 
	  
	        // if element is already there then insert into duplicate set 
	        else
	            duplicate.insert(arr[i]); 
	    } 
	  
	    // printing the result 
	    cout << "Duplicate item are : "; 
	    unordered_set<int> :: iterator itr; 
	  
	    // iterator itr loops from begin() till end() 
	    for (itr = duplicate.begin(); itr != duplicate.end(); itr++) 
	        cout << *itr << " "; 
	}

    */
    cout<<"****************************"<<"\n";

    multiset<int> s4;
	s4.insert(5);
	s4.insert(5);
	s4.insert(5);
	s4.insert(2);
	s4.insert(6);
	s4.insert(1);
	s4.insert(1);
	cout << s4.count(5) << "\n"; // 3
	s4.erase(5);// It removes all instances of 5 in the array
	//.Strange way to remove only one element
	//s4.erase(s4.find(5));

	for(auto x: s4){
		cout<<x<<"\n";
	}



	return 0;
}