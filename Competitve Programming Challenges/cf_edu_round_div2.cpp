//A-https://codeforces.com/contest/1633/problem/A
void solve()
{
    ll N;
    cin >> N;
    if(N%7==0)
    {
        cout<<N<<endl;
        return;
    }
    ll a = N / 7;
    ll n1 = a * 7;
    ll n2 = (a + 1) * 7;
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    string str = to_string(N);
    if (s1.length() == to_string(N).length() && s2.length() == to_string(N).length())
    {
        ll mina = 0;
        ll minb = 0;
        for (int i = 0; i < str.length(); i++)
        {
            mina += (str[i] != s1[i]);
        }
        for (int i = 0; i < str.length(); i++)
        {
            minb += (str[i] != s2[i]);
        }
        if(mina<minb)
        {
            cout<<s1<<endl;
        }
        else
            cout<<s2<<endl;
        return;
    }
    else if (s1.length() != to_string(N).length())
    {
        cout<<s2<<endl;return;
    }
    cout<<s1<<endl;
}
//B-https://codeforces.com/contest/1633/problem/B
void solve()
{
    string str;
    cin>>str;
    map<char,int> mp;
    for(auto &value:str)
        mp[value]++;
    if(mp['0']==mp['1'])
    {
        cout<<mp['0']-1<<endl;
    }
    else
        cout<<min(mp['0'],mp['1'])<<endl;
}
//C-https://codeforces.com/contest/1633/problem/C
void solve()
{
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc;
    cin >> hm >> dm;
    cin >> k >> w >> a;
    bool ans = false;
    for (int i = 0; i <= k; i++)
    {
        ll curr1 = hc+i*a;
        ll curr2 = dc+(k-i)*w;
        ll ok1,ok2;
        if(curr1%dm==0)
        {
            ok1=curr1/dm;
        }
        else
        {
            ok1 = curr1/dm + 1;
        }
        if(hm%curr2==0)
        {
            ok2 = hm/curr2;
        }
        else
        {
            ok2 = hm/curr2 + 1;
        }
 
        if (ok1 >= ok2)
        {
            ans = true;
            break;
        }
 
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}