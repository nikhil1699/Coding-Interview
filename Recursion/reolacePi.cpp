#include<iostream>
using namespace std;

int length(char mystr[]){
    return sizeof(mystr)/sizeof(mystr[0]);
}
void replacePi(char mystr[], int start){
    if(mystr[start]=='\0' || mystr[start+1]=='\0'){
        return ;
    }

    replacePi(mystr, start+1);
    if(mystr[start]=="p" && mystr[start+1]=="i"){
        len=length(mystr);
        //Create Space for new characters to come
        mystr[len+2]='\0';
        for (int i = len-1; i >= start+2; i--)
        {
            mystr[i+2]=mystr[i];
        }
        mystr[start]="3";mystr[start+1]=".";mystr[start+2]="1"; mystr[start+3]="4";

    }

}
int main(){
    char mystr[]='xpixpipixpi';
    replacePi(mystr,0);
    return 0;
}