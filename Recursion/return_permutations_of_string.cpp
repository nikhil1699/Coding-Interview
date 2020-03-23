#include <string>
using namespace std;

void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int returnPermutations(string input, string output[]){
    /* Don't write main() function.
  * Don't read input, it is passed as function argument.
  * Print output as specified in the question
 */
    int l=0;
    int r=input.size()-1;
    permute(input,l,r);

}
