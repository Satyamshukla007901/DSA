//https://leetcode.com/problems/longest-palindromic-substring/
// TC-->O(N^2)
// SC-->O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        int ans = 1;string str = "";
        str+=s[0];
        //odd length palindrome
        for(int i=0;i<l;i++)
        {
            int a = i;
            int b = i;
            while(a>=0 and b<s.length())
            {
                if(s[a]!=s[b])
                {
                    break;
                }
                a--;
                b++;
            }
            if(b-a-1>ans)
            {
                ans = b-a-1;str = s.substr(a+1,b-a-1);
            }
        }
        
        //even length palindrome
        for(int i=0;i<l;i++)
        {
            int a = i;
            int b = i+1;
           
                while(a>=0 and b<s.length())
                {
                    if(s[a]!=s[b])
                    {
                        break;
                    }
                    a--;
                    b++;
                
                }
                if(b-a-1>ans)
                {
                    ans = b-a-1;str = s.substr(a+1,b-a-1);
                }
          
        }
        return str;
        
    }
};