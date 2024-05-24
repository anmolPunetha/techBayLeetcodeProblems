class Solution {
public:
    int ans=0;
    int height(TreeNode* root){
        if(!root)return 0;
        int lsh=height(root->left);
        int rsh=height(root->right);
        return 1+max(lsh,rsh);
    }
    void helper(TreeNode* root){
        if(!root) return;

        //current root logic
        int lsh=height(root->left); //height of left subtree of the current root
        int rsh=height(root->right);
        int curr_dia=lsh+rsh;
        ans=max(ans, curr_dia);

        //traversing the tree
        helper(root->left);
        helper(root->right);
    }
    int dia_optimised(TreeNode* root){
        if(!root)return 0;

        int lsh=dia_optimised(root->left);
        int rsh=dia_optimised(root->right);
        int curr_dia=lsh+rsh;
        ans=max(ans, curr_dia);

        return 1+max(lsh,rsh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // helper(root);
        dia_optimised(root);
        return ans;
    }
};
