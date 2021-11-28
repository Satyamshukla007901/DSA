#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        string S;
        cin>>S;
        int ab=0;
        int ba=0;
        for(int i=0;i<S.length()-1;i++)
        {
            ab+=(S[i]=='a'&&S[i+1]=='b');
            ba+=(S[i]=='b')&&(S[i+1]=='a');
        }
        if(ab==ba)
            cout<<S<<endl;
        else
        {
            int l = S.length();
            if(S[l-1]=='a')
                S[l-1]='b';
            else
                S[l-1]='a';
            cout<<S<<endl;
        }
    }
    return 0;
}