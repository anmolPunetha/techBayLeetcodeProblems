class Solution:
    def helper(self, idx, arr, sum):
        if sum==0:
            return 1
        if idx == len(arr):
            return 0
        
        leave = self.helper(idx+1, arr, sum)
        take = 0
        if arr[idx]<=sum:
            take = self.helper(idx+1, arr, sum-arr[idx])
        
        ans = leave or take
        return ans
        
    def isSubsetSum (self, N, arr, sum):
        return self.helper(0, arr, sum)
