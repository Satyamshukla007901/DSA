//A - >https://www.codechef.com/START23C/problems/CHFPROFIT
void solve()
{
     ll X,Y,Z;
     cin>>X>>Y>>Z;
     cout<<X*Z-X*Y<<endl;
}
//B - >https://www.codechef.com/START23C/problems/AVGOF3
void solve()
{
     ll X;
     cin>>X;
     cout<<1<<" "<<3<<" "<<3*X-4<<endl;
}
//C - >https://www.codechef.com/START23C/problems/SUBMEX
void solve()
{
    ll N, K, X;
    cin >> N >> K >> X;
    if (X > K)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        vector<ll> vp;
        ll x = 0;map<ll,ll> mp;
        for (int i = 0; i < K; i++)
        {
            mp[x]++;
            vp.push_back(x);
            if (x < X - 1)
                x++;
        }
        ll ok = x;
        ll i = 1;
        mp[vp[0]]--;
        if(mp[vp[0]]==0)
        {
            ok=vp[0];
        }
        ll j = K;
        while(vp.size()<N)
        {
            vp.push_back(ok);
            mp[vp[j]]++;
            j++;
            mp[vp[i]]--;
            if(mp[vp[i]]==0)
            {
                ok=vp[i];
            }
            i++;
        }
        for(auto &value:vp)
        {
            cout<<value<<" ";
        }
        cout<<endl;
    }
}