class Solution:
    def isMidValPossible(self, mid, n, quantities):
        req_shops=0

        for q in quantities:
            # 8.5=>9
            # 15/7=>2.1=3
            req_shops+=q//mid
            if q%mid!=0:
                req_shops+=1
            
        if req_shops<=n:
            return True
        else:
            return False


    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        start=1
        end=0 #end option= max in the array
        for i in quantities:
            end=max(end, i)
        
        # range=monotonic ss=start(1) to end(max of all)

        ans=0
        while start<=end:
            mid=(start+end)//2
            if self.isMidValPossible(mid,n,quantities):
                ans=mid
                end=mid-1
            else:
                start=mid+1
            
        return ans
        

    

# TC: O(MlogZ), M=quantities length and Z=max prod count of any prod given

        


# [11,6]

#  1 2 3 4 5 6
# 11 6 0 0 0 0
# x=11

#  1 2 3 4 5 6
#  5 6 6 0 0 0
# x=6

#  1 2 3 4 5 6
#  2 3 3 3 3 3
#  11=2+3+3+3
#  6=3+3
#  x=3


# 1 2 3 4 5 6
# 1 2 2 2 4 6
# prod1=11
# x=6

# prod0=15
# prod1=10
# prod2=10

# 1  2  3  4 5 6 7
# 5  5  5  5 5 5 5
# x=5

