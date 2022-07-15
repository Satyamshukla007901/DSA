//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool binarySearch(vector<int> vp,int ok)
    {
        int s = 0;
        int e = vp.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(vp[mid]==ok)
                    return true;
            else if(vp[mid]>ok)
                    e=mid-1;
            else
                    s=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            if(binarySearch(matrix[i],target))
                    return true;
        }
        return false;
        
    }
};