//A - 
//https://codeforces.com/contest/1526/problem/A
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    for (int i = 1; i <= 2*N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
    }
    sort(vp.begin(),vp.end());
    ll i = 0;
    ll j = 2*N-1;
    while(i<j)
    {
        cout<<vp[i]<<" ";
        cout<<vp[j]<<" ";
        i++;j--;
    }
    cout<<endl;
}
//B - https://codeforces.com/contest/1526/problem/B
void solve()
{
 
    ll X;
    cin >> X;
 
    X = X - (X % 11) * 111;
    if (X >= 0 && X % 11 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}