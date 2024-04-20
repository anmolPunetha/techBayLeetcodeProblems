class Solution {
public:
    int maxSumSubArrayFunc(vector<int>&nums){
        int cs=0,ms=0;
        for(int &x:nums){
            cs+=x;
            if(cs<0) cs=0;
            ms=max(ms,cs);
        }
        return ms;
    }
    int minSumSubArrayFunc(vector<int>&nums){
        int cs=0,ms=0;
        for(int &x:nums){
            cs+=x;
            if(cs>0) cs=0;
            ms=min(ms,cs);
        }
        return ms;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;
        int largestNum=INT_MIN;
        for(int &x:nums){
            totalSum+=x;
            largestNum=max(largestNum, x);
        }
        int maxSum = maxSumSubArrayFunc(nums);
        int minSum = minSumSubArrayFunc(nums);
        int ans=max(maxSum, totalSum-minSum);
        if(largestNum<0) return largestNum; //when all numbers are negative
        return ans;
    }
};
