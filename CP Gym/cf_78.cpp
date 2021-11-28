#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long T;
    cin >> T;
    while (T-- > 0)
    {
        long long N;
        cin >> N;
        vector<long long> A(N);
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            sum += A[i];
        }
        int count = 0;
        long long newSum = 0;
        
        if (sum - 1 == 0)
            cout << count + 1 << endl;
        else
            cout << count << endl;
    }
    return 0;
}