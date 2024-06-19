class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        d={}
        csum=0
        ans=0
        d[0]=1
        for i in range(0, len(nums)):
            csum+=nums[i]
            req_sum=csum-k
            if req_sum in d:
                ans+=d[req_sum]

            if csum in d:
                d[csum]+=1
            else:
                d[csum]=1
        
        return ans
