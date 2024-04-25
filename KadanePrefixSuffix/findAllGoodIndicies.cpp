class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        //prefix array=decreasing nature
        //suffix array=increasing nature
        int n=nums.size();
        vector<int>decPrefix(n,1);
        vector<int>incSuffix(n,1);

        //pre
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                decPrefix[i]=decPrefix[i-1]+1;
            }
        }

        //suffix
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                incSuffix[i]=incSuffix[i+1]+1;
            }
        }

        vector<int>ans;
        for(int i=1;i<n-1;i++){
            if(decPrefix[i-1]>=k and incSuffix[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
