//Jump Game gfg
    int canReach(int A[], int N) {
        //Here we are moving throguh the max distance we can move from any index
        int ok = 0;
        for(int i=0;i<N;i++)
        {
            if(ok<i)
            {
                return 0;
            }
            ok=max(ok,A[i]+i);
        }
        return 1;
        // code here
    }