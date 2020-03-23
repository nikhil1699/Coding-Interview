#include<bits/stdc++.h>
using namespace std;
int main(){
		
	/*
	Lists are sequence containers that allow non-contiguous memory allocation.
	As compared to vector, list has slow traversal,
	but once a position has been found,
	insertion and deletion are quick.
	Normally, when we say a List, we talk about doubly linked list.
	For implementing a singly linked list, we use forward list.
	*/
	//Function to print all
	void showlist(list <int> g){ 
    	list <int> :: iterator it; 
    	for(it = g.begin(); it != g.end(); ++it){ 
        	cout << '\t' << *it; 
        }
    	cout << '\n'; 
	} 


	list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); //Pushing from back of LL
        gqlist2.push_front(i * 3); //From Front
    }

    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1); 
  
 
  	gqlist1.front(); //Accessing Head
    gqlist1.back(); //Accessing Tail
  
    
    gqlist1.pop_front(); //Remove head and make head->next the new head
    showlist(gqlist1); 
   
    gqlist2.pop_back(); //Remove current tail and make tail->prev as new tail
    showlist(gqlist2); 
  
    gqlist1.reverse(); //Reverse a ll
    showlist(gqlist1); 
  
   
    gqlist2.sort(); //Sort a ll
    showlist(gqlist2); 


    /*
	Functions used with List:

    front() – Returns the value of the first element in the list.

    back() – Returns the value of the last element in the list .

    push_front(g) – Adds a new element ‘g’ at the beginning of the list .

    push_back(g) – Adds a new element ‘g’ at the end of the list.

    pop_front() – Removes the first element of the list, and reduces size of the list by 1.

    pop_back() – Removes the last element of the list, and reduces size of the list by 1

    list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
    end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.

    
    empty() – Returns whether the list is empty(1) or not(0).

    insert(a,b) – Inserts new elements in the list before the element at a specified position.

    assign(a,b) – Assigns new elements to list by replacing current elements and resizes the list.

    remove(20) – Removes all the elements from the list, which are equal to given element.

    list::remove_if() in C++ STL– Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
    bool even(const int& value) { return (value % 2) == 0; } 
	mylist.remove_if(even); 

    reverse() – Reverses the list.

    size() – Returns the number of elements in the list.

    sort() – Sorts the list in increasing order.

    list max_size() function in C++ STL– Returns the maximum number of elements a list container can hold.

    list unique() in C++ STL– Removes all duplicate consecutive elements from the list.

    list::emplace_front() and list::emplace_back() in C++ STL– emplace_front() function is used to insert a new element into the list container, the new element is added to the beginning of the list. emplace_back() function is used to insert a new element into the list container, the new element is added to the end of the list.
    
    list::clear() in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.
    
    list::swap() in C++ STL– This function is used to swap the contents of one list with another list of same type and size.
    
    list splice() function in C++ STL– Used to transfer elements from one list to another.

    list merge() function in C++ STL– Merges two sorted lists into one

    list emplace() function in C++ STL– Extends list by inserting new element at a given position.


    */

    ************************************************************

//Stack
// The functions associated with stack are:
// empty() – Returns whether the stack is empty – Time Complexity : O(1)
// size() – Returns the size of the stack – Time Complexity : O(1)
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
// pop() – Deletes the top most element of the stack – Time Complexity : O(1)


**********************************************************************
//Queue
/*

    empty() – Returns whether the queue is empty.
    size() – Returns the size of the queue.
    queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
    queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
    queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
    push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
*/	
	void showq(queue <int> gq) { 
    	queue <int> g = gq; 
    	while (!g.empty()) 
    	{ 
        	cout << '\t' << g.front(); 
        	g.pop(); 
    	} 
    	cout << '\n'; 
	} 
  
    queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.front() : " << gquiz.front(); 
    cout << "\ngquiz.back() : " << gquiz.back(); 
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showq(gquiz); 

***************************************************
//Deque: Like a vector, a deque provides the functions push_back and pop_back ,
//but it also includes the functions push_front and pop_front which are not avail-
//able in a vector.
deque<int> d;
d.push_back(5); // [5]
d.push_back(2); // [5,2]
d.push_front(3); // [3,5,2]
d.pop_back(); // [3,5]
d.pop_front(); // [5]

****************************************************
//Priority Queue

/*
A priority queue maintains a set of elements. The supported operations are
insertion and, depending on the type of the queue, retrieval and removal of either
the minimum or maximum element. Insertion and removal take O (log n ) time,
and retrieval takes O (1) time.
By default, the elements in a C++ priority queue are sorted in decreasing
order, and it is possible to find and remove the largest element in the queue.
*/

priority_queue<int> q;
q.push(3);
q.push(5);
q.push(7);
q.push(2);
cout << q.top() << "\n"; // 7
q.pop();
cout << q.top() << "\n"; // 5
q.pop();
q.push(6);
cout << q.top() << "\n"; // 6
q.pop();

// If we want to create a priority queue that supports finding and removing the
// smallest element, we can do it as follows:
priority_queue<int,vector<int>,greater<int>> q;





	return 0;
}