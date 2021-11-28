#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define fasio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
int main() {
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N;
        cin>>N;
        vector<int> vp;
        multimap<int,int> mp;
        for(int i=1;i<=N;i++)
        {
            int X;
            cin>>X;
            vp.push_back(X);
            mp.insert({X,i-1});
        }
        // cout<<"--"<<endl;
        // for(auto &value:mp)
        //     cout<<value.first<<" "<<value.second<<endl;
        int rem=0;
        vector<int> v(N);
        for(auto &value:mp)
        {
            if(rem>=value.first)
            {
                v[value.second]=value.first;
            }
            else
            {
                v[value.second]=rem;
                rem++;
            }

        }
        for(auto &value:v)
            cout<<value<<" ";
        cout<<endl;
        for(int i=0;i<N;i++)
        {
            cout<<v[i]%vp[i]<<" ";
        }
        cout<<endl;

       

    }
	// your code goes here
	return 0;
}
