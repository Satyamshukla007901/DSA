//A - https://codeforces.com/contest/1520/problem/A
void solve()
{
   ll N;
   cin>>N;
   string str;
   cin>>str;
   unordered_map<char,int> mp;
   for(auto &value:str)
   {
       mp[value]++;
   }
   for(int i =0;i<N;)
   {
       char value=str[i];
       if(str[i+mp[value]-1]!=value)
       {
           cout<<"NO"<<endl;return;
       }
       i+=mp[value];
   }
   cout<<"YES"<<endl;
}
//B - https://codeforces.com/contest/1520/problem/B
void solve()
{
   ll N;
   cin>>N;
   string str;
   cin>>str;
   unordered_map<char,int> mp;
   for(auto &value:str)
   {
       mp[value]++;
   }
   for(int i =0;i<N;)
   {
       char value=str[i];
       if(str[i+mp[value]-1]!=value)
       {
           cout<<"NO"<<endl;return;
       }
       i+=mp[value];
   }
   cout<<"YES"<<endl;
}
//C - https://codeforces.com/contest/1520/problem/C
void solve()
{
   ll N;
   cin>>N;
   string str;
   cin>>str;
   unordered_map<char,int> mp;
   for(auto &value:str)
   {
       mp[value]++;
   }
   for(int i =0;i<N;)
   {
       char value=str[i];
       if(str[i+mp[value]-1]!=value)
       {
           cout<<"NO"<<endl;return;
       }
       i+=mp[value];
   }
   cout<<"YES"<<endl;
}