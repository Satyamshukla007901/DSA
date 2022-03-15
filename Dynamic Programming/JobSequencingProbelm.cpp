https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
    static bool compare(Job &a,Job &b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // isme max profit har baar niklaaelnge aur usko uski deadlien se kam samaay par end krenge taaki max profit deadline ke pehel aapaaye
        sort(arr,arr+n,compare);
        int maxe = arr[0].dead;
        for(int i=1;i<n;i++)
            maxe = max(maxe,arr[i].dead);
        vector<int> ans(maxe+1,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>=1;j--)
            {
                if(ans[j]==-1)
                {
                    ans[j]=i;
                    break;
                }
            }
        }
        int cnt = 0;
        int profit = 0;
        for(auto &value:ans)
        {
            if(value!=-1)
            {
                cnt++;
                profit+=arr[value].profit;
            }
        }
        return {cnt,profit};
        // your code here
    } 