
#include<bits/stdc++.h>
using namespace std;
class StackUsingArray{
	int* data;
	int nextIndex;
	int capacity;

public:
	StackUsingArray(int totalSize){
		data=new int[totalSize];
		nextIndex=0;
		capacity=totalSize;
	}
	int sizeOfStack(){
		return nextIndex;
	}
	bool isEmpty(){
		return nextIndex==0;
	}
	void push(int element){
		if(nextIndex==capacity){
			cout<<"Stack is full"<<endl;
			return;
		}
		else{
			data[nextIndex]=element;
			nextIndex++;
		}
	}
	int pop(){
		if(isEmpty()==true){
			cout<<"Stack is empty"<<endl;
			return INT_MIN;
		}else{
			nextIndex--;
			return data[nextIndex];
		}
	}
	int top(){
		if(isEmpty()==true){
			cout<<"Stack is empty"<<endl;
			return INT_MIN;
		}else{
			return data[nextIndex-1];
		}
	}

};
int main(){
	StackUsingArray s1(5);
	s1.push(10);s1.push(20);s1.push(30);s1.push(40);s1.push(50);s1.push(60);
	cout<<s1.sizeOfStack()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.sizeOfStack()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.isEmpty()<<endl<<endl;
	cout<<"Fucking Simple Bro"<<endl;
	return 0;
}
