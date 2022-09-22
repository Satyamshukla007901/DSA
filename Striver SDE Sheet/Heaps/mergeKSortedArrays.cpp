//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1
#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({kArrays[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        auto it = pq.top();
        ans.push_back(it.first);
        pq.pop();
        if(it.second.second+1<kArrays[it.second.first].size())
        {
            pq.push({kArrays[it.second.first][it.second.second+1],{it.second.first,it.second.second+1}});
        }
    }
    return ans;
    // Write your code here. 
}
