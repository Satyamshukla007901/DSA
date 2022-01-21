//A https://codeforces.com/contest/1608/problem/A
void solve()
{
    ll N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
}
//B https://codeforces.com/contest/1608/problem/B
void solve()
{
    ll N, A, B;
    cin >> N >> A >> B;
    if (abs(A - B) > 1)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<ll> vp;
        for (int i = 0; i < N; i++)
        {
            vp.push_back(i + 1);
        }
        if (A > B)
        {
            ll idx = N - 1;
            ll a = A;
            while (a-- > 0 && idx >= 0)
            {
                if (idx - 1 >= 0)
                    swap(vp[idx], vp[idx - 1]);
                idx -= 2;
            }
            ll cnt1 = 0;
            ll cnt2 = 0;
            for (int i = 1; i < N - 1; i++)
            {
                if (vp[i - 1] < vp[i] && vp[i] > vp[i + 1])
                {
                    cnt1++;
                }
                else if (vp[i - 1] > vp[i] && vp[i] < vp[i + 1])
                {
                    cnt2++;
                }
            }
            if (cnt1 == A && cnt2 == B)
            {
                for (auto &value : vp)
                    cout << value << " ";
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (B > A)
        {
            ll idx = 0;
            ll b = B;
            while (idx < N && b-- > 0)
            {
                if (idx + 1 < N)
                {
                    swap(vp[idx], vp[idx + 1]);
                }
                idx += 2;
            }
            ll cnt1 = 0;
            ll cnt2 = 0;
            for (int i = 1; i < N - 1; i++)
            {
                if (vp[i - 1] < vp[i] && vp[i] > vp[i + 1])
                {
                    cnt1++;
                }
                else if (vp[i - 1] > vp[i] && vp[i] < vp[i + 1])
                {
                    cnt2++;
                }
            }
            if (cnt1 == A && cnt2 == B)
            {
                for (auto &value : vp)
                    cout << value << " ";
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (A == B && A == 0)
        {
            for (auto &value : vp)
                cout << value << " ";
            cout << endl;
        }
        else if (A == B && N % 2 == 0)
        {
            ll idx = N - 1;
            ll a = A;
            while (a-- > 0 && idx >= 0)
            {
                if (idx - 1 >= 0)
                    swap(vp[idx], vp[idx - 1]);
                idx -= 2;
            }
            ll b = B - A + 1;
            idx = 0;
            while (idx < N && b-- > 0)
            {
                if (idx + 1 < N)
                {
                    swap(vp[idx], vp[idx + 1]);
                }
                idx += 2;
            }
            ll cnt1 = 0;
            ll cnt2 = 0;
            for (int i = 1; i < N - 1; i++)
            {
                if (vp[i - 1] < vp[i] && vp[i] > vp[i + 1])
                {
                    cnt1++;
                }
                else if (vp[i - 1] > vp[i] && vp[i] < vp[i + 1])
                {
                    cnt2++;
                }
            }
            // for(auto &value:vp)
            //     cout<<value<<" ";
            // cout<<endl;
            if (cnt1 == A && cnt2 == B)
            {
                for (auto &value : vp)
                    cout << value << " ";
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (A == B && N % 2 != 0)
        {
            ll idx = N - 1;
            ll a = A;
            while (a-- > 0 && idx >= 0)
            {
                if (idx - 1 >= 0)
                    swap(vp[idx], vp[idx - 1]);
                idx -= 2;
            }
            ll b = B - A + 1;
            idx = 0;
            while (idx < N && b-- > 0)
            {
                if (idx + 1 < N)
                {
                    swap(vp[idx], vp[idx + 1]);
                }
                idx += 2;
            }
            ll cnt1 = 0;
            ll cnt2 = 0;
            for (int i = 1; i < N - 1; i++)
            {
                if (vp[i - 1] < vp[i] && vp[i] > vp[i + 1])
                {
                    cnt1++;
                }
                else if (vp[i - 1] > vp[i] && vp[i] < vp[i + 1])
                {
                    cnt2++;
                }
            }
            // for(auto &value:vp)
            //     cout<<value<<" ";
            // cout<<endl;
            if (cnt1 == A && cnt2 == B)
            {
                for (auto &value : vp)
                    cout << value << " ";
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}