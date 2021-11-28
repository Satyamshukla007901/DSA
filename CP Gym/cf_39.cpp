#include <iostream>
using namespace std;
#define lli long long int
int32_t main()
{
    lli T;
    cin >> T;
    while (T-- > 0)
    {
        int n, k;
        cin >> n >> k;
        if (k > n)
            cout << -1 << endl;
        else if (k == n - 1)
            cout << -1 << endl;
        else if (n == k)
        {
            for (lli i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            for(lli i=1;i<=k;i++)
            {
                cout<<i<<" ";
            }
            for(lli i=k+2;i<=n;i++)
            {
                cout<<i<<" ";
            }
            cout<<k+1<<endl;
        }
    }
    return 0;
}