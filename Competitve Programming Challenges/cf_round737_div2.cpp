//A- https://codeforces.com/contest/1557/problem/A
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
        sum+=X;
    }
    ll maxe = *max_element(vp.begin(),vp.end());
    double ans = maxe+(double)(sum-maxe)/(double)(N-1);
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
//B- https://codeforces.com/contest/1557/problem/B
void solve()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> vp;bool flag = true;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
    }
    for(int i=0;i<N-1;i++)
    {
        if(vp[i]>vp[i+1])
        {
            flag =  false;
            break;
        }
    }
    if(K==N)
    {
        cout<<"YES"<<endl;
    }
    else if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        set<ll> s;
        for(auto &value:vp)
        {
            s.insert(value);
        }
        ll cnt = 0;
        auto it = s.find(vp[0]);
        for(int i=1;i<N;i++)
        {
            ++it;
            if(s.find(vp[i])!=it)
            {
                cnt++;
                it = s.find(vp[i]);
            }
 
        }
        if((cnt+1)<=K)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}