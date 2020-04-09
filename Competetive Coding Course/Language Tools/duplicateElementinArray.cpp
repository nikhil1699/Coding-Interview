// arr - input array
// size - size of array
#include<unordered_map>
int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
    }
    unordered_map<int,int> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        if(it->second>1){
            return it->first;
        }
    }
    

}
