class Solution {
public:
    int height(TreeNode* root){ //h1=from the bottom to that current node::postorder
        if(!root) return 0;

        int lsh=height(root->left);
        int rsh=height(root->right);

        return 1+max(lsh,rsh);
    }

    int maxLevel=0;
    void height2(TreeNode* root, int level){ //h2=from top to the current node::preorder
        if(!root)return;
        //preoerder traversal
        if(level>maxLevel){
            maxLevel=level;
        }
        height2(root->left, level+1);
        height2(root->right, level+1);
    }
    int maxDepth(TreeNode* root) {

        height2(root,1);
        return maxLevel;
        //return height(root);
    }
};
