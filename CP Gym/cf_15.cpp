#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long N;
        string S,str;
        cin>>N>>S>>str;
        long long count=0;
        for(int i=0;i<N;i++)
        {
            if(str[i]=='1')
            {
                if(S[i]=='0')
                    count++;
                else if(i>0&&S[i-1]=='1')
                {
                    count++;
                    S[i-1]='0';
                }
                else if(i<N&&S[i+1]=='1')
                {
                    count++;
                    S[i+1]='0';
                }
            }
        }
        cout<<count<<endl;
    }
}