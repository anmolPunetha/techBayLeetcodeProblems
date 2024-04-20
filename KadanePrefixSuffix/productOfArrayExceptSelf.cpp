class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixProd(n);
        vector<int>suffixProd(n);

        //prefix
        for(int i=0;i<n;i++){
            if(i==0){
                prefixProd[i]=nums[i];
                continue;
            }
            prefixProd[i]=prefixProd[i-1]*nums[i];
        }

        //suffix
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suffixProd[i]=nums[i];
                continue;
            }
            suffixProd[i]=suffixProd[i+1]*nums[i];
        }

        //generating the final ans array
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(i==0) ans[i]=suffixProd[i+1];
            else if(i==n-1) ans[i]=prefixProd[i-1];
            else ans[i]=prefixProd[i-1]*suffixProd[i+1]; //prod except self
        }
        return ans;
    }
};
