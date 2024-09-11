class Solution:
    dp=[]
    def helper(self, idx, arr, sum):
        if sum==0:
            return 1  # true
        if idx == len(arr):
            return 0  # False
        
        #look up case
        if self.dp[sum][idx]!=-1:
            return self.dp[sum][idx]
        
        leave = self.helper(idx+1, arr, sum)
        take = 0 
        if arr[idx]<=sum:
            take = self.helper(idx+1, arr, sum-arr[idx])
        
        ans = leave or take # if any value is true, ans is true
        self.dp[sum][idx] = ans
        return ans

    def canPartition(self, nums: List[int]) -> bool:
        sum_ = sum(nums)
        if sum_%2 !=0 :
            return False
        
        req_sum = sum_//2
        self.dp = [[-1]*len(nums) for i in range(req_sum+1)]
        return self.helper(0, nums, req_sum)

#(sum Of Array) is not even, then you can't divide into 2 parts
#nowhere its written that you want actual subset ==> just T/F
#if u r able to find 1 subset with a sum of TS/2
# so remaining will be just part of other subset
# u have got 2 subsets with equal sum


# subset problem:: sum = TS/2 , do u have a subset?

# 1,5,11,5
# sum = 11 ==22/2
# can u find a subset with sum 11 or not==true

# we found the target sum for one subset == sum/2
# find a subset with this given target sum ===> SUBSET PROBLEM


# 10==some element with total sum 10
# total = +=val
# total==sum

# sum -=
# sum -=
# this sum becomes 0, meaning i have taken the elements
