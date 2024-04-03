class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        start=0
        end=len(nums)-1
        mid=0
        while mid<=end:
            if nums[mid]==0:
                #swap it with start pointer
                nums[start],nums[mid]=nums[mid],nums[start]
                start+=1
                mid+=1
        
            elif nums[mid]==1:
                mid+=1
            
            elif nums[mid]==2:
                nums[end],nums[mid]=nums[mid],nums[end]
                end-=1


#app-1
'''
counting/bucket sort

nums=[2,0,0,1,2,1,2]
0count=2
1count=2
2count=3
nums=[0,0,1,1,2,2,2]
O(N)->2 pass solution
'''

#app-2
#single pass
#start->group0
#end->group2

