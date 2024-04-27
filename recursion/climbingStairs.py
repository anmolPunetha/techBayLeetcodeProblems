class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[-1]*46
        def helper(n,dp):
            if n==1:
                return 1
            if n==2:
                return 2
            if dp[n]!=-1:
                return dp[n]

            dp[n]=helper(n-1,dp)+helper(n-2,dp)
            return dp[n]
        

        return helper(n,dp)
