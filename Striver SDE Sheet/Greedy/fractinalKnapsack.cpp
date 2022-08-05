//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
    static bool cmp(Item a,Item b)
    {
        double ok1 = double(a.value)/double(a.weight);
        double ok2 = double(b.value)/double(b.weight);
        return ok1>ok2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double ans = 0.0;
        for(int i=0;i<n;i++)
        {
            double ok = double(arr[i].value)/double(arr[i].weight);
            if(arr[i].weight<=W)
            {
                ans+=ok*arr[i].weight;
                W-=arr[i].weight;
                
            }
            else
            {
                
                ans+=ok*W;
                W=0;
            }
            // if(W==0) break;
        }
        return ans;
        // Your code here
    }