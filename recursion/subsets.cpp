class Solution {
public:
    vector<vector<int>>ans; //saving all the subsets here
    void helper(int idx, vector<int>& nums, vector<int>&curr_nums){
        //base case
        if(idx==nums.size()){
            ans.push_back(curr_nums);  //a deep copy is made
            return;
        }

        //main structure
        //picking the number
        curr_nums.push_back(nums[idx]);
        helper(idx+1, nums, curr_nums);

        curr_nums.pop_back();  //backtracking step->undoing the change

        //leave the number
        helper(idx+1,nums,curr_nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr_nums;
        helper(0, nums, curr_nums);
        return ans;
    }
};
// ans.append(curr_nums.copy())
// l=[]
// l=curr_nums
