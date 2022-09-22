//https://leetcode.com/problems/implement-stack-using-queues/submissions/
class MyStack {
public:
    /*
    queue<int> q1;
    queue<int> q2;*/
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for(int i=1;i<sz;i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty())
                return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */