#include <bits/stdc++.h>
using namespace std;

// Change in the given string itself. So no need to return or print anything
int strlength(char input[]){
    return sizeof(input)/sizeof(input[0]);
}
void removeX(char input[]) {
    // Write your code here
   if(input[0]=='\0'){
       return;
   }
    removeX(input+1);
    if(input[0]=='x'){
         input[0]='\0';
    }
}


int main()
{
    
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
    
    return 0;
}
