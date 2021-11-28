#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1073741824
int32_t main()
{
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        ll N;
        cin >> N;
        ll A[N];
        ll count = 0;
        for (ll i = 0; i < N; i++)
        {
            cin >> A[i];
            if (A[i] % 2 != 0)
                count++;
        }
        if (count >= 1)
            cout << 0 << endl;
        else
        {
            
            ll mn = INT_MAX;
            for (ll i = 0; i < N; i++)
            {
                ll temp=A[i];ll pow = 0;
                while(temp%2!=1)
                {
                    temp=temp/2;
                    pow++;
                }
                mn = min(mn,pow);
            }
            cout<<mn<<endl;
        }
    }
    return 0;
}