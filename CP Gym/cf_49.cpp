#include <bits/stdc++.h>
using namespace std;
 
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int A[26];
        for(int i=0;i<26;i++)
            cin>>A[i];
        
        string S;
        cin>>S;
        map<char,int> mp;
        for(int i=0;i<S.length();i++)
            mp[S[i]]++;
        string str="";
        for(auto &value:mp)
            str+=value.first;
        string temp = "abcdefghijklmnopqrstuvwxyz";
        if(str.length()==temp.length())
        {
            cout<<0<<endl;
        }
        else
        {
            long long sum=0;
            // for(int i=0;i<str.length();i++)
            // {
            //     bool res=false;
            //     for(int i=0;i<26;i++)
            //     {
            //         if(str[i]==temp[i])
            //         {
            //             res=true;
            //             break;
            //         }
            //     }
            //     if(!res)
            //     {
            //         sum+=A[(int)str[i]-97];
            //     }
            // }
            for(int i=0;i<26;i++)
            {
                bool res=false;
                for(int j=0;j<str.length();j++)
                {
                    if(str[j]==temp[i])
                    {
                        res=true;
                        break;
                    }
                }
                if(!res)
                {
                    sum+=A[i];
                }
            }
            // cout<<str<<endl;
            cout<<sum<<endl;
            // cout<<"here"<<endl;
        }

    }
    return 0;
}