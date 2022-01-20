//Find the Smallest Divisor Given a Threshold
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution
{
public:
    bool isPossible(int mid, vector<int> &vp, int x)
    {
        int sum = 0;
        for (auto &value : vp)
        {
            sum += ceil((double)value / (double)mid);
        }
        if (sum <= x)
            return true;
        return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(mid, nums, threshold))
            {
                ans = mid; // mid is looking for a smaller ans so this can be possible but we also search on left
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
//Split Array Largest Sum
//https://leetcode.com/problems/split-array-largest-sum/
class Solution
{
public:
    bool isPossible(int mid, vector<int> &vp, int m)
    {
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            int a = 0;
            while (idx < vp.size() && vp[idx] <= mid && a + vp[idx] <= mid)
            {
                a += vp[idx];
                idx++;
            }
            if (a == 0)//if u can make even subarrays less than m then also ans possible
                break;
        }
        if (idx != vp.size())
        {
            return false;
        }
        return true;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = s;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(mid, nums, m))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};