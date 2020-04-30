#include <bits/stdc++.h>
using namespace std;

bool checkAB(char* input, int index=0){

    if(input[index]=='\0'){
        return true;
    }
    if(input[0]!= 'a'){
        return false;
    }
    bool flag;
    if(input[index]=='a'){
        if(input[index+1]=='a'){
            flag=checkAB(input,index+1);
        }
        else if(input[index+1]=='b' && input[index+2]=='b'){
            flag=checkAB(input, index+1);
        }
        else if(input[index+1]=='\0'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(input[index]=='b' && input[index+1]=='b'){
        if(input[index+2]=='a'){
            flag=checkAB(input, index+2);
        }
        else if(input[index+2]=='\0'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    return flag;

}



int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
    
    
    return 0;
}
