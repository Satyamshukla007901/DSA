 struct compare{
       bool operator()(pair<int,int>a,pair<int,int>b){
           if(a.first==b.first){
               return a.second<b.second;
           }
           return a.first>b.first;
           
       }
   };
    vector<int> printKClosest(vector<int> vp, int n, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<n;i++)
        {
            if(x-vp[i]!=0)
            {
                pq.push({abs(x-vp[i]),vp[i]});
                
            }

        }
        while(!pq.empty()&&k-->0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
        // code here
    }


//My Approach
 struct compare{
       bool operator()(pair<int,int>a,pair<int,int>b){
           if(a.first==b.first){
               return a.second>b.second;
           }
           return a.first<b.first;
           
       }
   };
    vector<int> printKClosest(vector<int> vp, int n, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<n;i++)
        {
            if(x-vp[i]!=0)
            {
                pq.push({abs(x-vp[i]),vp[i]});
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }

        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        // code here
    }