//A->https://codeforces.com/contest/1644/problem/A
void solve()
{
    string str;
    cin >> str;
    set<char> keys;
    for (auto &value : str)
    {
        if (value == 'r' || value == 'g' || value == 'b')
            keys.insert(value);
        else
        {
            if(value=='R'&&keys.find('r')==keys.end())
            {
                cout<<"NO"<<endl;return;
            }
            else if(value=='G'&&keys.find('g')==keys.end())
            {
                cout<<"NO"<<endl;return;
            }
            else if(value=='B'&&keys.find('b')==keys.end())
            {
                cout<<"NO"<<endl;return;
            }
        }
    }
    cout<<"YES"<<endl;
}
//B->https://codeforces.com/contest/1644/problem/B
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp(N + 1);
    for (int i = 1; i <= N; i++)
        vp[i] = i;
    reverse(vp.begin() + 1, vp.end());
    for (int i = 1; i <= N; i++)
        cout << vp[i] << " ";
    cout << endl;
    for (int i = N; i >= 2; i--)
    {
        if (i - 1 >= 1)
        {
            swap(vp[i], vp[i - 1]);
        }
        for (int i = 1; i <= N; i++)
            cout << vp[i] << " ";
        cout << endl;
    }
}