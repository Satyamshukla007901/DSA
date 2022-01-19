//A - https://codeforces.com/contest/1529/problem/A
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    map<ll, ll> mp;
    ll mine = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        ll X;
        cin >> X;
        mp[X]++;
        vp.push_back(X);
        mine = min(mine, X);
    }
    ll cnt = 0;
    for (auto &value : mp)
    {
        if (value.second > cnt)
        {
            cnt = value.second;
        }
    }
    if (mp[mine] == cnt)
        cout << N - cnt << endl;
    else
        cout << N - mp[mine] << endl;
}
//B - https://codeforces.com/contest/1529/problem/B
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    ll cnt = 0;
    vector<ll> neg;ll mine = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
        if(X<=0)
        {
            neg.push_back(X);
        }
        if(X<=0)
        {
            cnt++;
        }
        if(X>0)
        {
            mine=min(mine,X);
        }
    }
    sort(neg.begin(),neg.end());
    bool flag = false;
    for(int i=1;i<neg.size();i++)
    {
        if(abs(neg[i]-neg[i-1])<mine)
        {
            flag = true;break;
        }
    }
    if(mine==INT_MAX)
    {
        cout<<cnt<<endl;
    }
    else if(flag)
    {
        cout<<cnt<<endl;
    }
    else
        cout<<cnt+1<<endl;
    
    
}