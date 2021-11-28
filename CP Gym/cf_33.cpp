#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int j = 1;
    while (j <= n)
    {
        int i = j;
        while(i<=((n*n)/2))
        {
                cout << i << " " << (n * n) - i + 1 << " ";
                i+=n;
        }
        cout<<endl;
        j++;
    }

    return 0;
}