#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int N;
        cin>>N;
        string S;
        cin>>S;int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<=min(i+9,N-1);j++)
            {
                if(j-i == abs(S[i]-S[j]))
                    count++;
            }
        }
        cout<<count<<endl;
    }
}