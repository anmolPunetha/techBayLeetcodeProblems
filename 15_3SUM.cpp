class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans; //i will be saving the triplets
        int n=nums.size();
        sort(nums.begin(), nums.end());
        //ascending order of values are there
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]){ //handle duplicate cases of same target
                continue;
            }
            //c=nums[i]
            int c=nums[i];
            int k=-c;
            //now in the range of i+1 to the end
            //i have to find a pair
            int start=i+1, end=n-1;
            while(start<end){
                int curr_sum=nums[start]+nums[end];
                if(curr_sum<k){
                    start+=1;
                }else if(curr_sum>k){
                    end-=1;
                }else{
                    ans.push_back({c, nums[start], nums[end]});
                    int end_ele=nums[end], start_ele=nums[start];
                    while(start<end and nums[start]==start_ele){
                        start+=1;
                    }

                    while(start<end and nums[end]==end_ele){
                        end-=1;
                    }
                }
            }
        }
        return ans;
    }
};
