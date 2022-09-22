//https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include <bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    //brute force
    vector<int> arr;
    for(auto &value:matrix)
    {
        for(auto &val:value)
        {
            arr.push_back(val);
        }
    }
    sort(arr.begin(),arr.end());
    int N = arr.size();
    return arr[N/2];
        
    // Write your code here.
}