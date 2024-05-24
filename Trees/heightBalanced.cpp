class Solution {
public:
    bool ans=true;
    
    int helper(TreeNode* root){
        if(!root)return 0;

        int lsh=helper(root->left);
        int rsh=helper(root->right);

        if(abs(lsh, rsh)>1){ //whether that root node is height balanced or not
            ans=false;
        }

        return 1+max(lsh,rsh); //height getting returned
    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
};
