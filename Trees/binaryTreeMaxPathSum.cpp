class Solution {
public:
    int max_path_sum=INT_MIN;
    int helper(TreeNode* root){
        if(!root)return 0;
        int lbs=helper(root->left); //left
        int rbs=helper(root->right); //right

        //current node path sum //root
        int op1=root->val;
        int op2=root->val+lbs;
        int op3=root->val+rbs;
        int op4=root->val+lbs+rbs;
        max_path_sum=max({max_path_sum,op1,op2,op3,op4});

        return max({lbs,rbs,0})+root->val; //branch sum=returned to the parent calls
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_path_sum;
    }
};
