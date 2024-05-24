/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //stack::list::LIFO
        //queue::list
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        
        //approach1
        // ans.push_back({}); //empty vector is inserted
        // q.push(root);
        // q.push(NULL);
        // while(!q.empty()){
        //     TreeNode* f=q.front(); //f is the node
        //     q.pop();
        //     //f can be null, or can be non-null node
        //     if(f==NULL){
        //         if(!q.empty()){
        //             q.push(NULL);
        //             ans.push_back({});
        //         }
        //     }else{
        //         int value=f->val;
        //         ans.back().push_back(value);

        //         if(f->left!=NULL)
        //             q.push(f->left);
        //         if(f->right!=NULL)
        //             q.push(f->right);
        //     }
        // }
        // return ans;

        //approach2
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>current_level;
            //sz bascially denotes the number of nodes of current level
            while(sz--){
                TreeNode* f=q.front(); //f is the node
                q.pop();
                int value=f->val;
                current_level.push_back(value);

                if(f->left!=NULL)
                    q.push(f->left);
                if(f->right!=NULL)
                    q.push(f->right);
            }
            //i have all the nodes in my current level vector
            ans.push_back(current_level);
        }
        return ans;
    }

};


