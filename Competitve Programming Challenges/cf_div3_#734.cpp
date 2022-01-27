//A - >https://codeforces.com/contest/1551/problem/A
void solve()
{
   ll N;
   cin>>N;
   if(N%3==0)
   {
       cout<<N/3<<" "<<N/3<<endl;return;
   }
   else if(N%3==1)
   {
       cout<<N/3+1<<" "<<N/3<<endl;return;
   }
   else
   {
       cout<<N/3<<" "<<N/3+1<<endl;return;
   }
}
//B - >https://codeforces.com/contest/1551/problem/B1
void solve()
{
    string str;
    cin >> str;
    map<char, ll> mp;
    for (auto &value : str)
        mp[value]++;
    ll r = 0;
    ll g = 0;
    bool flag = false;
    for (auto &value : mp)
    {
        if (value.second >= 2)
        {
            if (flag)
            {
                g++;
                flag = false;
                r++;
                flag = true;
            }
            else
            {
                r++;
                flag = true;
                g++;
                flag = false;
            }
        }
        else
        {
            if (flag)
            {
                g++;
                flag = false;
            }
            else
            {
                r++;
                flag = true;
            }
        }
    }
    cout<<min(r,g)<<endl;
}