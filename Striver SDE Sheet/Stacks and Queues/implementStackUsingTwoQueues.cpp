//https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty())
                return -1;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int item = q1.front();
        q1.pop();
        while(q2.empty()!=true)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return item;
    }
    
    int top() {
        if(q1.empty())
                return -1;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int item = q1.front();
        q2.push(item);
        q1.pop();
        while(q2.empty()!=true)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return item;
    }
    
    bool empty() {
        if(q1.empty())
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