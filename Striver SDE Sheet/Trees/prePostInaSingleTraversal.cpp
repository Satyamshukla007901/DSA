//https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/

void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
    stack<pair<Node*,int>> st;
    st.push({root,1});
    if(root==NULL) return;

    while(!st.empty())
    {
        Node* node = st.top().first;
        int vis  = st.top().second;
        st.pop();
        if(vis==1)
        {
            pre.push_back(root->data);
            vis++;
            st.push({root,vis});
            if(node->left)
            {
                st.push({node->left,1});
            }
        }
        else if(vis==2)
        {
            in.push_back(root->data);
            vis++;
            st.push({root,vis});
            if(node->right)
            {
                st.push({node->right,2});
            }
        }
        else
        {
            post.push_back(node->data);
        }
    }
}