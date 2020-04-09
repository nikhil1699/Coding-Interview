#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Check weather ith bit is set or not, ie its value is 1 or not
    // 5 00000101 0th and second bit are set
    // X & 0 is 0 
    // X &  1 is X
    // for any ith bit, take a number witn all bits 0 but the bit we wanna check ie, ith bit as 1 and take bitwise and with given number
    // If all are 0, then number doesn't have ith bit set
    // the number which will check is actually 2^i
    // Now inbuilt power function has complexity log(n)
    //Use M<<i to calculate 1*2^i
    //Z=N & (1<<i)
    int N;
    cout<<"Enter the number"<<endl;
    cin>>N;
    int z=N & (1<<i);
    if(z!=0){
        cout<<"true";
    }
    else{
        cout<< "false";
    }
    
    
    return 0;
}

