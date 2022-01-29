//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
void StackQueue :: push(int x)
{
    s1.push(x);
    // Your Code
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()==true)
        return -1;
    while(s1.size()!=1)
    {
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }
    int item = s1.top();
    s1.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return item;
        // Your Code       
}