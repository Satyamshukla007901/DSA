#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int N;
    cin>>N;
    vector<int> vp;int one=0;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        vp.push_back(x);
        one+=(x==1);
    }
    if(N==1&&vp[0]==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int sum=0;
    int left=0;
    int right=0;int maxi=INT_MIN;
    for(int i=0;i<N;i++)
    {
        right=i;
        sum+=(vp[i]==0);
        if(vp[i]==1)
        {
            left++;
            one--;
        }
        maxi=max(maxi,sum);
    }
    cout<<one+maxi<<endl;

    return 0;
}