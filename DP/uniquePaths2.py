class Solution:
    dp=[]
    def helper(self, m, n, i , j, grid):
        # base cases
        if i==m or j==n:
            return 0 #wrong path
        
        # obstacle found
        if grid[i][j]==1:
            return 0

        if i==m-1 and j==n-1:
            return 1  #found a path

        #lookup case
        if self.dp[i][j]!=-1:
            return self.dp[i][j]

        # main structure
        # 2 options- down call, right call
        down = self.helper(m,n,i+1,j,grid)
        right = self.helper(m,n,i,j+1,grid)

        ans = down+right
        self.dp[i][j]=ans
        return ans
        
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n=len(grid[0])
        self.dp = [[-1]*n for i in range(m)]
        return self.helper(m,n,0,0,grid) 
