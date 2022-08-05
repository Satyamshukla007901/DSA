//https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    map<int,int> mp;
    int cnt = 0;
    int ok = 0;
    for(auto &value:arr)
    {
        ok=ok^value;
        if(ok==x) cnt++;
        
        if(mp.find(ok^x)!=mp.end())
        {
            cnt+=mp[ok^x];
        }
        mp[ok]++;
    }
    return cnt;
    //    Write your code here.
}