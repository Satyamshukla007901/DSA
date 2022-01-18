//https://leetcode.com/problems/find-common-characters/submissions/
//find common character
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        map<char, int> mp;
        for (auto &value : words[0])
            mp[value]++;
        map<char, int> visi;
        for (auto &value : words[0])
        {
            int ok = mp[value];
            if (visi[value] == 0)
            {

                visi[value] = 1;
                for (int i = 1; i < words.size(); i++)
                {
                    map<char, int> ump;
                    for (auto &val : words[i])
                    {
                        ump[val]++;
                    }
                    // cout << value << ump[value] << mp[value] << endl;
                    ok = min(ump[value], ok);
                }

                // cout<<value<<" "<<ok<<endl;
                string hm = "";
                hm += value;
                for (int i = 1; i <= ok; i++)
                    ans.push_back(hm);
            }
        }
        return ans;
    }
};