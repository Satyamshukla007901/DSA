//https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
void QueueStack :: push(int x)
{
    q1.push(x);
        // Your Code
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty()==true)
        return -1;
    
    int temp = q1.back();
    while(q1.size()!=1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return temp;
    
        // Your Code       
}