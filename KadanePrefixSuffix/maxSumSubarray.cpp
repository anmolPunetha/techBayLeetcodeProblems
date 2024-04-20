class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ms=0;
        int maxNum=INT_MIN; //smallest possible integer
        for(int x:nums){
            cs+=x;
            if(cs<0) cs=0;
            ms=max(ms,cs);

            maxNum=max(x,maxNum);
        }
        if(maxNum<0)return maxNum;
        return ms;
    }
};
