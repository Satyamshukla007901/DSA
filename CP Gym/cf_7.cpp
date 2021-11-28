#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int arr[m+1];
    for(int i=0;i<=m;i++)
        cin>>arr[i];
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        int temp = arr[i]^arr[m];
        int ones = 0;
        while(temp)
        {
            temp&=(temp-1);
            ones++;
        }
        if(ones<=k)
            ans++;
    }
    cout<<ans<<endl;
}