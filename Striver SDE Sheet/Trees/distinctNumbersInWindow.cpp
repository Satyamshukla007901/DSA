//https://www.interviewbit.com/problems/distinct-numbers-in-window/
// TC->O(N)
// SC->O(N)

vector<int> Solution::dNums(vector<int> &A, int B) {
  
    map<int,int> mp;
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(j<A.size())
    {
        mp[A[j]]++;
        if(j-i+1<B)
        {
            j++;
        }
        else if(j-i+1>=B)
        {
            while(j-i+1>B)
            {
                mp[A[i]]--;
                if(mp[A[i]]==0) mp.erase(A[i]);
                i++;
            }
            if(j-i+1==B)
            {
                ans.push_back(mp.size());
            }
            j++;
        }
        
    }
    return ans;
}
