void helper(Node* root, int level, vector<int>&ans, int &maxLevel){
    if(!root)return;
    //modified preorder= root, right, left

    if(level>maxLevel){
        //this node needs to be taken
        ans.push_back(root->data);
        maxLevel=level;
    }
    
    helper(root->left, level+1, ans, maxLevel);
    helper(root->right, level+1, ans, maxLevel);
}
vector<int> leftView(Node *root)
{
    vector<int>ans; //saving the req nodes
    int maxLevel=0;
    helper(root, 1, ans, maxLevel);
    return ans;
}
