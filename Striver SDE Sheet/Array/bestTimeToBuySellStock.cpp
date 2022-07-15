//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxe = 0;
    int mini = prices[0];
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]<mini)
        {
            mini = prices[i];
        }
        else
        {
            maxe = max(maxe,prices[i]-mini);
        }
    }
    return maxe;