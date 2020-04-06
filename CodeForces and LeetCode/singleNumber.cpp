   #include<bits/stdc++.h>
   using namespace std;
   
   
   
    int returnSquaresum(int n){
        int currSum;
        while(n!=0 ){
            currSum+=(n%10);
            n=n/10;
        }
        return currSum;
    }

    int main(){
        cout<<returnSquaresum(45);
    }