//https://leetcode.com/problems/clone-graph/
//TC->O(N+E)
//SC->O(N+E)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*> &mp)
    {
        vector<Node*> neighbors;
        Node* clone = new Node(node->val);
        mp[node]=clone;
        for(auto &value:node->neighbors)
        {
            if(mp.find(value)!=mp.end())
            {
                neighbors.push_back(mp[value]);
            }
            else
            {
                neighbors.push_back(dfs(value,mp));
            }
        }
        clone->neighbors = neighbors;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)return NULL;
        if(node->neighbors.size()==0)return new Node(node->val);
        
        return dfs(node,mp);
    }
};