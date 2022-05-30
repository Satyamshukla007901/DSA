//A https://leetcode.com/problems/largest-3-same-digit-number-in-string/
class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = INT_MIN;
        
        for(int i=0;i<num.length();i++)
        {
            if(i+2<num.length() and num[i]==num[i+1] and num[i+1] == num[i+2])
            {
                ans = max(ans,num[i]-'0');
            }
        }
        
        if(ans == INT_MIN)
            return "";
        string ok = "";
        ok+=to_string(ans);ok+=to_string(ans);ok+=to_string(ans);
        
        return ok;
    }
};
//B https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root,int &cnt)
    {
        if(root==NULL) return 0;
        cnt++;
        return root->val+sum(root->left,cnt)+sum(root->right,cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        else if(root->left == NULL and root->right==NULL)
            return 1;
        int ans = 0;
        int cnt = 0;
        int s = sum(root,cnt);
        if(s/cnt == root->val) ans = 1;
        int l = averageOfSubtree(root->left);
        int r = averageOfSubtree(root->right);
        
        return l+r+ans;
    }
};
//C https://leetcode.com/problems/count-number-of-texts/
class Solution {
public:
    int f(int ind,string p,vector<string> &vp,vector<int> &dp)
    {
        if(ind>=p.length()-1)
            return 1;
        
        if(dp[ind]!=-1) return dp[ind]%1000000007;
        
        
        int a = f(ind+1,p,vp,dp)%1000000007;
        int b = 0;
        if(ind+1<p.length() and p[ind+1]==p[ind]) b = f(ind+2,p,vp,dp)%1000000007;
        int c = 0;
        if(ind+2<p.length() and p[ind+2]==p[ind]&&p[ind+1]==p[ind]) c = f(ind+3,p,vp,dp)%1000000007;
        int d = 0;
        if(ind+3<p.length() and (p[ind]=='7' or p[ind]=='9') and p[ind+3]==p[ind] and p[ind+2]==p[ind]&&p[ind+1]==p[ind]) d = f(ind+4,p,vp,dp)%1000000007;
        
        return dp[ind] = ((a%1000000007+b%1000000007)%1000000007+(c%1000000007+d%1000000007)%1000000007)%1000000007;
        
    }
    int countTexts(string p) {
        
        vector<string> vp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // vector<int> dp(pressedKeys.length(),-1);
        // return f(0,pressedKeys,vp,dp)%1000000007;
        
        vector<int> dp(p.length()+4,0);
        int n = p.length()+4;
        for(int i=p.length()-1;i<=n-1;i++)
            dp[i]=1;
        for(int ind=n-2;ind>=0;ind--)
        {
            int a = dp[ind+1]%1000000007;
            int b = 0;
            if(ind+1<p.length() and p[ind+1]==p[ind]) b = dp[ind+2]%1000000007;
            int c = 0;
            if(ind+2<p.length() and p[ind+2]==p[ind]&&p[ind+1]==p[ind]) c = dp[ind+3]%1000000007;
            int d = 0;
            if(ind+3<p.length() and (p[ind]=='7' or p[ind]=='9') and p[ind+3]==p[ind] and p[ind+2]==p[ind]&&p[ind+1]==p[ind]) d =           dp[ind+4]%1000000007;
            
            dp[ind] = ((a%1000000007+b%1000000007)%1000000007+(c%1000000007+d%1000000007)%1000000007)%1000000007;
            
        }
        return dp[0];
        
    }
};