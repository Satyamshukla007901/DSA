//A - >https://codeforces.com/contest/1635/problem/A
void solve()
{
    ll N;
    cin>>N;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        vp.push_back(X);
    }
    vector<ll> ok(32,0);
    for(auto &value:vp)
    {
        for(int i=0;i<32;i++)
        {
            if((value>>i)&1)
            {
                ok[i]=1;
            }
        }
    }
    ll num = 0;
    for(int i=0;i<32;i++)
    {
        num=num+pow(2,i)*ok[i];
    }
    cout<<num<<endl;
}
//B - >https://codeforces.com/contest/1635/problem/B
void solve()
{
    ll N;
    cin>>N;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        vp.push_back(X);
    }
    ll cnt = 0;
    for(int i=1;i<N-1;i++)
    {
        if(vp[i]>vp[i-1]&&vp[i]>vp[i+1])
        {
            cnt++;
            if(i+2<N)
                vp[i+1]=max(vp[i],vp[i+2]);
            else
                vp[i+1]=vp[i];
        }
    }
    cout<<cnt<<endl;
    for(auto &value:vp)
    {
        cout<<value<<" ";
    }
    cout<<endl;
}

//C - https://codeforces.com/contest/1635/problem/C
void solve()
{
    ll N;
    cin>>N;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        vp.push_back(X);
    }
    ll cnt = 0;
    vector<vector<ll>> ok;
    if(vp[N-2]>vp[N-1])
    {
        cout<<-1<<endl;return;
    }
    ll a = vp[N-2];
    ll adx = N-2;
    ll b = vp[N-1];
    ll bdx = N-1;
    for(int i=N-3;i>=0;i--)
    {
        if(i+1<N&&vp[i]>vp[i+1])
        {
            vp[i]=a-b;
            cnt++;
            ok.push_back({i+1,adx+1,bdx+1});
        }
        if(vp[i]<a)
        {
            a=vp[i];
            adx=i;
        }
        if(vp[i]>b)
        {
            b=vp[i];
            bdx=i;
        }
    }
    // for(auto &value:vp)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<N;i++)
    {
        if(i+1<N&&vp[i]>vp[i+1])
        {
            cout<<-1<<endl;return;
        }
    }
    cout<<cnt<<endl;
    for(auto &value:ok)
    {
        cout<<value[0]<<" "<<value[1]<<" "<<value[2]<<endl;
    }
}