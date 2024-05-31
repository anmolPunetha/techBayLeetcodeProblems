class Solution {
public:
    int idx=0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start>end){
            return NULL;
        }

        int val=preorder[idx]; //i have to search this in inorder array from start to end
        int i=-1;
        for(int j=start;j<=end;j++){
            if(inorder[j]==val){
                i=j;
                break;
            }
        }
        idx+=1;

        TreeNode*root=new TreeNode(val);
        root->left=helper(preorder,inorder,start,i-1);
        root->right=helper(preorder,inorder,i+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start=0, end=inorder.size()-1; //for the searchspace
        //dictionary=saving the values and index of inorder
        return helper(preorder,inorder,start,end);
    }
};
