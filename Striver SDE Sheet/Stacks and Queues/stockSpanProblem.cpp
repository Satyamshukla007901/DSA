class StockSpanner {
public:
    stack<pair<int,int>> st;
    int top=-1;
    StockSpanner() {
        top=-1;
    }
    
    int next(int price) {
        top++;
        

        while(!st.empty()&&st.top().first<=price)
        {
            st.pop();
        }
        bool flag =  false;int x;
        if(st.empty())
                flag= true;
        else
            x=st.top().second;
    
        st.push({price,top});
        if(flag)
                return top+1;
        else
                return top-x;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */