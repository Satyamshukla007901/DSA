//https://www.codechef.com/FEB221B/problems/CHEFBARBER
void solve()
{
     ll N,M;
     cin>>N>>M;
     cout<<N*M<<endl;
}
//https://www.codechef.com/FEB221B/problems/EUREKA
void solve()
{
     ll N;
     cin>>N;
     double ok = pow((0.143*N),N);
     ll f = floor(ok);
     if(ok-(double)f<0.5)
     {
          cout<<f<<endl;
     }
     else
          cout<<f+1<<endl;
}
//https://www.codechef.com/FEB221B/problems/BINBASBASIC
bool isPalin(string str)
{
    ll i = 0;
    ll j = str.length()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve()
{
    ll N,K;
    cin>>N>>K;
    string str;
    cin>>str;
    if(K==0&&isPalin(str))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        ll cnt = 0;
        ll i = 0;
        ll j = str.length()-1;
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                cnt++;
            }
            i++;
            j--;
        }
        if(K<cnt)
        {
            cout<<"NO"<<endl;
        }
        else if(cnt<=K&&N%2==1)
        {
            cout<<"YES"<<endl;
        }
        else if(cnt==K&&N%2==0)
        {
            cout<<"YES"<<endl;
        }
        else if(cnt<K&&N%2==0)
        {
            ll rem = K-cnt;
            if(rem%2==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}