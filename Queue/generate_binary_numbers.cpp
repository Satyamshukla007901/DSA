//https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1
vector<string> generate(int N)
{
    vector<string> vp;
    string str="";
    queue<string> q;
    q.push("1");
    for(int i=1;i<=N;i++)
    {
        string ok = q.front();
        vp.push_back(ok);
        q.pop();
        string a = ok+"0";
        string b = ok+"1";
        q.push(a);
        q.push(b);
    }
    return vp;
	// Your code here
}