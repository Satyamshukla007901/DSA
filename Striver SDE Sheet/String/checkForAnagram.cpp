//https://leetcode.com/problems/valid-anagram
// TC-->O(NlogN + MlogM)
// SC-->O(1)
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }

// TC-->O(N+M)
// SC-->O(1)
map<char,int> ok1;
map<char,int> ok2;
for(auto &value:str1) ok1[value]++;
for(auto &value:str2) ok2[value]++;
for(char ch='a';ch<='z';ch++)
{
    if(ok1[ch]!=ok2[ch]) return false;
}
return true;