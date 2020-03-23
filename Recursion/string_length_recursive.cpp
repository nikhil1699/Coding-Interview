#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int length(char s[]){
if(s[0]=='\0'){
				return 0;
}
int smallString=length(s+1);
return 1+smallString;
}

int main()
{
				char str[100];
				cin>>str;
				int l=length(str);
				cout<<l<<endl;


return 0;
}

