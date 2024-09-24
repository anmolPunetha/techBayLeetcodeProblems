class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        #grid of size m*n, after which it is a traversal
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        grid = [[0]*n for i in range(m)]
        
        #feed the initial values
        #the first row and the col=>1
        for j in range(n):
            if obstacleGrid[0][j]==1: #if not an obstacle
                break
            grid[0][j]=1

        for i in range(m):
            if obstacleGrid[i][0]==1: #if not an obstacle
                break
            grid[i][0]=1
            
        #the main loops
        for i in range(1,m):
            for j in range(1, n):
                if obstacleGrid[i][j]!=1:
                    grid[i][j] = grid[i-1][j] + grid[i][j-1]
  
        return grid[m-1][n-1]
