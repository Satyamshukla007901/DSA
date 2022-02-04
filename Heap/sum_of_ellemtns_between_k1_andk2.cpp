//https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1/
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<pair<long long,int>> pq;
        for(int i=0;i<N;i++)
        {
            pq.push({A[i],i});
            if(pq.size()>K1)
                pq.pop();
        }
        long long idx1 = pq.top().first;
        while(!pq.empty())
            pq.pop();
        for(int i=0;i<N;i++)
        {
            pq.push({A[i],i});
            if(pq.size()>K2)
                pq.pop();
        }
       long long idx2 = pq.top().first;
       int sum = 0;
       for(int i=0;i<N;i++)
       {
           if(A[i]>min(idx1,idx2)&&A[i]<max(idx1,idx2))
                sum+=A[i];
       }
        return sum;
        // Your code goes here
    }