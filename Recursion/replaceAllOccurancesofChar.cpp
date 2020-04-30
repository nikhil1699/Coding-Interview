#include <bits/stdc++.h>
using namespace std;

int length(char input[]){
    int len=0;
    for(int i=0; input[i] != '\0';i++){
        len++;
    }
    return len;
}
void replaceCharacter(char input[], char c1, char c2) {
    if(length(input)==0){
        return;
    }
    replaceCharacter(input+1,c1,c2);
    if(input[0]==c1){
        input[0]=c2;
    }  
}

int main()
{
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl; 
    return 0;
}
