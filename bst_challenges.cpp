#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node* root,int val)
{
    if(!root)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->left = insertBST(root->left,val);
    }
    else
    {
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inorder(Node* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//Search in BST
//Time Complexity is O(logN)
Node* searchInBST(Node* root,int key)
{
    if(!root)
        return NULL;
    
    if(root->data==key){
        return root;
    }
    if(key<root->data)
    {
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}
//Delete in BST
//Function for finding inorder succesor
Node* inorederSucc(Node* root)
{
    Node* curr = root;
    while(curr&&curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}
//function for deleting the node
Node* deleteBST(Node* root,int key)
{
    if(key<root->data)
    {
        root->left = deleteBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deleteBST(root->right,key);
    }

    else{
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorederSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}
//Construct Binary Search tree from preorder Sequence
Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n)
{
    if(*preorderIdx>=n){return NULL;}

    Node* root = NULL;
    if(key>min&&key<max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx+1;

        if(*preorderIdx<n)
        {
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n)
        {
            root->right = constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}
void preorder(Node* root)
{
    if(!root)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//Build BST from Sorted array
Node* sortedArrayToBst(vector<int> arr,int start,int end)
{
    if(start>end){return NULL;}

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);


    root->left = sortedArrayToBst(arr,start,mid-1);

    root->right = sortedArrayToBst(arr,mid+1,end);


    return root;
}
//Catalan Numbers : High Time Complexity method
int catalan(int n)
{
    if(n<=1)
        return 1;

    int res = 0;
    for(int i=0;i<=n-1;i++)
    {
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}
//BST count using Catalan Concept
vector<Node*> constructTrees(int start,int end)
{
    vector<Node*> trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i = start;i<=end;i++)
    {
        vector<Node*> leftsubtrees = constructTrees(start,i-1);

        vector<Node*> rightsubtrees = constructTrees(i+1,end);

        for(int j=0;j<leftsubtrees.size();j++)
        {
            Node* left = leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++)
            {
                Node* right = rightsubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
       
    }
     return trees;
}
int32_t main()
{
    
    // Node* root = NULL;
    // root = insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);
    /*
        5
       / \
      1   7
       \
        3
       / \
      2   4
    */
    // Print Inorder
    // inorder(root);
    // cout<<endl;
    // int x;
    // cin>>x;
    // if(searchInBST(root,x)==NULL)
    // {
    //     cout<<"Key does'nt Exist"<<endl;
    // }
    // else
    // {
    //     cout<<"key Exist"<<endl;
    // }
    // root = deleteBST(root,x);
    // inorder(root);
    // preorder(root);
    // cout<<endl;
    // int preorder1[] = {5,1,3,2,4,7};
    // int n=6;
    // int preorderIdx = 0;
    // Node* root1 = constructBST(preorder1,&preorderIdx,preorder1[0],INT_MIN,INT_MAX,n);
    // preorder(root1);
    // cout<<endl;
    // int n;
    // cin>>n;
    // vector<int> vp;
    // for(int i=0;i<n;i++)
    // {
    //     int x;
    //     cin>>x;
    //     vp.push_back(x);
    // }
    // sort(vp.begin(),vp.end());
    // Node* root = sortedArrayToBst(vp,0,n-1);
    // preorder(root);
    // cout<<endl;
    /*
       30
      /  \
     10   40
       \    \
        20   50
    */
    // for(int i=0;i<10;i++)
    // {
    //     cout<<catalan(i)<<" ";
    // }
    // cout<<endl;
    // return 0;

    vector<Node*> totalTrees = constructTrees(1,3);
    // constructtrees(1,3);
    for(int i=0;i<totalTrees.size();i++)
    {
        cout<<i+1<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;


}