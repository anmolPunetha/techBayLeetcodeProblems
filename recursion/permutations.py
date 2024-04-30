class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        idx=0

        def helper(nums, idx):
            # base case
            if idx==len(nums):
                #save the permutation in ans
                ans.append(nums.copy())
                return
            
            for i in range(idx, len(nums)):
                # i,idx are to be swapped
                nums[i], nums[idx] = nums[idx], nums[i]
                helper(nums, idx+1)
                nums[i], nums[idx] = nums[idx], nums[i] # re swap, backtracking step
            
        
        helper(nums, 0)
        return ans
