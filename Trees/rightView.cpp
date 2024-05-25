class Solution {
public:
    vector<int>ans; //saving the req nodes
    int maxLevel=0;

    void helper(TreeNode* root, int level){
        if(!root)return;
        //modified preorder= root, right, left

        if(level>maxLevel){
            //this node needs to be taken
            ans.push_back(root->val);
            maxLevel=level;
        }

        helper(root->right, level+1);
        helper(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 1);
        return ans;
    }
};
