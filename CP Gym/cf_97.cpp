#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    vector<int> b;
    vector<int> g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    int m;
    cin>>m;vector<int> vp;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        g.push_back(x);
        vp.push_back(0);
    }
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(abs(b[i]-g[j])<=1&&vp[j]!=1)
            {
                ans++;
                vp[j]=1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}