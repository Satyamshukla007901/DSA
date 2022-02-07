//A - https://codeforces.com/contest/1353/problem/A
void solve()
{
    ll N,M;
    cin>>N>>M;
    if(N==1)
    {
        cout<<0<<endl;
    }
    else if(N==2)
    {
        cout<<M<<endl;
    }
    else if(N==3)
    {
        cout<<M*2<<endl;
    }
    else 
    {
        if(M==1)
        {
            cout<<2<<endl;return;
        }
        else
        {
            cout<<2*M<<endl;
        }
    }
}
//B - https://codeforces.com/contest/1353/problem/B
void solve()
{
    ll N,M;
    cin>>N>>M;
    if(N==1)
    {
        cout<<0<<endl;
    }
    else if(N==2)
    {
        cout<<M<<endl;
    }
    else if(N==3)
    {
        cout<<M*2<<endl;
    }
    else 
    {
        if(M==1)
        {
            cout<<2<<endl;return;
        }
        else
        {
            cout<<2*M<<endl;
        }
    }
}
//C-https://codeforces.com/contest/1353/problem/C
vector<ll> prefix(500005,0);
void solve()
{
    ll N;
    cin>>N;
    if(N==1)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<prefix[N]<<endl;
    }
}