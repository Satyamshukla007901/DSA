#include <bits/stdc++.h> 
using namespace std;
int32_t main() 
{
      long long T;
      cin>>T;
      while(T-->0)
      {
            string S;
            long long N;
            cin>>N;
            cin>>S;
            unordered_map<long long ,long long>mp;
            for(long long i=0;i<N;i++)
            {
                  if(S[i]=='?')
                  {
                        if(i>0)
                        {
                              if(S[i-1]=='R')S[i]='B';
                              else S[i]='R';
                        }
                        else 
                        {
                            
                              if(S[i+1]=='R')S[i]='B';
                              else if(S[i+1]=='B') S[i]='R';
                              else
                              {
                                    long long j=1,count=1;
                                    char ans='R';
                                    while(j<N)
                                    {
                                          if(S[j]=='R') 
                                          {
                                               if(count&1) ans='B';
                                               else ans='R';
                                               break;
                                          }
                                          else if(S[j]=='B')
                                          {
                                                if(!(count&1)) ans='B';
                                                else ans='R';
                                                break;
                                          }
                                          count++;
                                          j++;
                                    }
                                    S[i]=ans;
                              }
                        }
                  }
            }
            cout<<S<<endl;
      }
	return 0;
}