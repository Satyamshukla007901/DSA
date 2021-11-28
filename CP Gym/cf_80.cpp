#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum = 0, simi = 0;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        if (N & 1)
        {
            int zero[N / 2 + 1], one[N / 2];
            for (int i = 0; i < N / 2 + 1; i++)
            {
                zero[i] = A[i * 2];
            }
            sort(zero, zero + N / 2 + 1, greater<int>());
            for (int i = 0; i < N / 2; i++)
            {
                one[i] = A[i * 2 + 1];
            }
            sort(one, one + N / 2);
            for (int i = 0; i < N; i++)
            {
                if (!(i & 1))
                    A[i] = zero[i / 2];
                else
                    A[i] = one[i / 2];
            }
            for (int i = 0; i < N; i++)
            {
                if (!(i & 1))
                {
                    for (int j = i + 1; j < N; j += 2)
                        simi += A[j];
                    sum += (A[i] * simi);
                    simi = 0;
                }
            }
            for (int i = 0; i < N; i++)
            {
                cout << A[i] << " ";
            }
            cout << "\n";
            cout << sum << "\n";
        }

        else
        {
            int zero[N / 2], one[N / 2];
            for (int i = 0; i < N / 2; i++)
            {
                zero[i] = A[i * 2];
            }
            sort(zero, zero + N / 2, greater<int>());
            for (int i = 0; i < N / 2; i++)
            {
                one[i] = A[i * 2 + 1];
            }
            sort(one, one + N / 2);
            for (int i = 0; i < N; i++)
            {
                if (!(i & 1))
                    A[i] = zero[i / 2];
                else
                    A[i] = one[i / 2];
            }
            for (int i = 0; i < N; i++)
            {
                cout << A[i] << " ";
            }
            for (int i = 0; i < N; i++)
            {
                if (!(i & 1))
                {
                    for (int j = i + 1; j < N; j += 2)
                        simi += A[j];
                    sum += (A[i] * simi);
                    simi = 0;
                }
            }
            cout << "\n";
            cout << sum << "\n";
        }
    }
    return 0;
}