//https://leetcode.com/problems/min-stack/submissions/
class MinStack {
public:
    /*
    int tp=-1;
    int arr[100000];
    MinStack() {
        tp=-1;
    }
    
    void push(int val) {
        tp++;
        arr[tp]=val;
    }
    
    void pop() {
        if(tp!=-1)
            tp--;
    }
    
    int top() {
        if(tp!=-1)
            return arr[tp];
        return -1;
    }
    
    int getMin() {
        
        int mine = INT_MAX;
        for(int i=0;i<=tp;i++)
        {
            mine=min(mine,arr[i]);
        }
        return mine;
    }*/
    /*
    stack<pair<int,int>> st;
    
    MinStack() {
      
    }
    
    void push(int val) {
        if(st.size())
        {
            if(val<st.top().second) st.push({val,val});
            else st.push({val,st.top().second});
        }
        else st.push({val,val});
    }
    
    void pop() {
        if(st.size()) st.pop();
    }
    
    int top() {
            
        if(st.size())
        {
            int val = st.top().first;
            return val;
        }
        return -1;
    }
    
    int getMin() {
        
        if(st.size()) 
            return st.top().second;
        return -1;
    }*/
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */