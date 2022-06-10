// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/
// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
void path(Node* root,vector<Node*> &vp,bool &flag,int B)
{
    if(root==NULL)
        return;
    if(root->data==B)
    {
        flag = true;
    }

    if(!flag)
        path(root->left,vp,flag,B);
    if(!flag)
        path(root->right,vp,flag,B);
    if(flag==true)
        vp.push_back(root);
    
}
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL)
                return NULL;
        bool flag = false;
        vector<Node*> a;
        unordered_set<int> s;

        path(root,a,flag,p);
        for(auto &value:a)
                s.insert(value->data);
        vector<Node*> b;
        flag = false;
        path(root,b,flag,q);
       
        for(auto &value:b)
        {
            if(s.find(value->data)!=s.end())
                    return value;
        }
        return NULL;
        
    }
    int d(Node* root,int a,bool &flag)
    {
        if(root==NULL) return INT_MIN;
        if(root->data == a){ flag = true;return 0;}
        int left = 0;
        if(!flag)
            left = 1+d(root->left,a,flag);
        int right = 0;
        if(!flag)
            right = 1+d(root->right,a,flag);
        return max(left,right);
        
        
    }
    int findDist(Node* root, int a, int b) {
        Node* lca = lowestCommonAncestor(root,a,b);
        bool flag = false,t=false;
        return d(lca,a,flag)+d(lca,b,t);
        // Your code here
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends