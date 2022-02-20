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