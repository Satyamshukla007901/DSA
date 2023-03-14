//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
// TC->O(N)
// SC->O(N)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
vector<vector<Node*>> levelOrder(Node *root)
{
    vector<vector<Node*>> vp;
    if (root == NULL)
        return vp;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<Node*> t;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *temp = q.front();
            // cout<<temp->val<<" ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            t.push_back(temp);
        }
        // cout << endl;
        vp.push_back(t);
    }
    return vp;
}
    Node* connect(Node* root) {
        /*
        vector<vector<Node*>> vp = levelOrder(root);
        for(auto &value:vp)
        {
            for(int i=0;i<value.size();i++)
            {
                if(i+1==value.size())
                {
                    value[i]->next = NULL;
                }
                else
                    value[i]->next = value[i+1];
            }
        }
        return root;*/
        Node* temp = root;
        while(temp)
        {
            Node* ok = temp;
            while(ok)
            {
                if(ok->left)
                    ok->left->next  = ok->right;
                if(ok->next)
                {
                    
                    if(ok->right)
                        ok->right->next = ok->next->left;
                }
                ok=ok->next;
            }
            temp = temp->left;
        }
        return root;
    }
};