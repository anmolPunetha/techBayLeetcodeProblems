class Solution {
  public:
    map<int,pair<int,int>>mp;//key=verLevel, value=(node,depth)
    void helper(Node*root, int verLevel, int horLevel){
        if(!root)return;
        
        //if coming at verlevel for the first time
        if(mp.find(verLevel)==mp.end()){
            mp[verLevel]={root->data,horLevel};
        }
        else{ //for that level, a node is already there, check the depth
            int prev_depth = mp[verLevel].second;
            if(prev_depth<=horLevel){
                //i need to overwrite with the current node
                mp[verLevel]={root->data,horLevel};
            }
        }
        
        helper(root->left,verLevel-1,horLevel+1);
        helper(root->right,verLevel+1,horLevel+1);
    }
    vector <int> bottomView(Node *root) {
        //pre-order
        //verLevel,depth
        helper(root, 0, 1);
        vector<int>ans; //save the nodes here
        for(auto &node:mp){
            ans.push_back(node.second.first); //node->data
        }
        return ans;
    }
};
