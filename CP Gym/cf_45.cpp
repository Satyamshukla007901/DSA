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
        string str="";
        int A[26]={0};
        bool B[26]={false};
        for(auto &value : S)
        {
            A[value-97]++;
        }
        for(int i=0;i<S.length();i++)
        {
            if(!B[S[i]-97])
            {
                str+=S[i];
                B[S[i]-97]=true;
            }
        }
        cout<<str<<endl;

    }
    return 0;
}