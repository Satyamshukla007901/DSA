//https://leetcode.com/problems/string-to-integer-atoi/
// TC-->O(N)
// SC-->O(1)
class Solution {
public:
    int myAtoi(string s) {
        
        int check = 1;
        long  long ans = 0;
        int i = 0;
        int l = s.length();
        
        //removing leading whitespace
        while(i<l and s[i]==' ')
            i++;
        
        //check for sign
        if(s[i]=='-')
        {
            check = -1;i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        
        //removing leading zeroes 
        while(i<l and s[i]=='0') i++;
        int cnt = 0;
        
        while(i<l and s[i]>='0' and s[i]<='9' and cnt<12)
        {
            ans = ans*10 + (s[i]-'0');
            cnt++;
            i++;
        }
        
        ans = ans*check;
        if(ans>=INT_MAX) return INT_MAX;
        else if(ans<=INT_MIN) return INT_MIN;
        return ans;
        
    }
};