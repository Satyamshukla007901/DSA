//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long sum=0;
        while(pq.size()>1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            sum+=a+b;
            pq.push(a+b);
        }
        return sum;
        // Your code here
    }