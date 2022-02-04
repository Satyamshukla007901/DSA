//https://codeforces.com/problemset/problem/1368/A
void solve()
{
    ll A, B, N;
    cin >> A >> B >> N;
    ll cnt = 0;
    while(A<=N&&B<=N)
    {
        if(A<B)
        {
            A+=B;
        }
        else
        {
            B+=A;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}
int main()
{
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    // your code goes here
    return 0;
}
