#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string S;
        cin>>S;
        unordered_map<char,int> m;
        int count1=0,count2=0;
        for(int i=0;i<S.length();i++)
        {
            m[S[i]]++;
        }
        for(auto value:m)
        {
            if(value.second>1)
            {
                count1++;
            }
            else
                count2++;
        }
        cout<<count1+count2/2<<endl;
    }
}