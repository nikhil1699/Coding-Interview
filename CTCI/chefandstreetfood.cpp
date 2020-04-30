#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, i, j, sale[102], max, s, p, v, n;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin>>n;
        for (j = 0; j < n; j++)
        {
            cin>>s>>p>>v;
            sale[j] = (int((p / (s + 1))) * v);
        }
        max = sale[0];
        for (j = 0; j < n - 1; j++)
        {
            if (sale[j + 1] > max)
            {
                max = sale[j + 1];
            }
        }
        cout<< max<<endl;
    }
}