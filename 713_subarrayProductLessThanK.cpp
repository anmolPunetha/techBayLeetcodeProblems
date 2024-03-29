class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int start=0;
        int prod=1;
        for(int j=0;j<nums.size();j++){
            //extending my window
            prod*=nums[j];

            //try to shrink if needed
            while(start<=j and prod>=k){
                prod/=nums[start];
                start+=1;
            }

            //if there are some elements in ur window=>form new subarrays
            //subarrays ending at j=>focusing on these only
            int newSubarrays=j-start+1;
            count+=newSubarrays;
        }
        return count;
    }
};

//app-1
/*
for i in range(0, n-1):
    prod=1;
    for j in range(i, n-1):
        prod*=nums[j]
        if prod<k:
            ans+=1
*/

// n~=3*10^4
// O(N^2)=>9*10^8~=10^9 should be less than 10^8

