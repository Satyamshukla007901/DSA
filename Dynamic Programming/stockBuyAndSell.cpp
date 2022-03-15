//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&A[i]<A[i+1])
            {
                vector<int> temp(2);
                temp[0]=i;
                temp[1]=i+1;
                ans.push_back(temp);
            }
        }
        return ans;
        // code here
    }