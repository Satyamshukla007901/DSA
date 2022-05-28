//https://leetcode.com/contest/biweekly-contest-78/problems/find-the-k-beauty-of-a-number/
#include <bits/stdc++.h>
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string ok = to_string(num);
        int i = 0;
        int j = 0;int cnt = 0;string c = "";
        while(j<ok.size())
        {
            c+=ok[j];
            if(j-i+1<k)
                    j++;
            else if(j-i+1==k)
            {
                
                int n = atoi(c.c_str());
                if(n!=0&&num%n==0) cnt++;
                c = c.substr(1,c.size()-1);
                // cout<<c<<endl;
                j++;i++;
            }
        }
        return cnt;
    }
};