class Solution:
    dp=[]
    def helper(self, m, n, i , j):
        # base cases
        if i==m or j==n:
            return 0 #wrong path
        
        if i==m-1 and j==n-1:
            return 1  #found a path

        #lookup case
        if self.dp[i][j]!=-1:
            return self.dp[i][j]

        # main structure
        # 2 options- down call, right call
        down = self.helper(m,n,i+1,j)
        right = self.helper(m,n,i,j+1)

        ans = down+right
        self.dp[i][j]=ans
        return ans

    def uniquePaths(self, m: int, n: int) -> int:
        self.dp = [[-1]*n for i in range(m)]
        return self.helper(m,n,0,0)
    
#how can any approach work? -maths/ recursion/ greedy
#how recursion will help?
#do we need to memoise the results?
