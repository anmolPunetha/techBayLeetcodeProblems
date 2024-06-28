class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dx=[-1,0,1,0]
        dy=[0,1,0,-1]

        def dfs(i, j):
            if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]!='1':
                return
            
            #grid[i][j] is a land patch
            grid[i][j]='2'

            '''
            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)
            '''

            for k in range(4):
                ii=i+dx[k]
                jj=j+dy[k]
                dfs(ii,jj)

            return

        ans=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=='1':
                    #make a dfs call from a unvisited land patch
                    dfs(i,j)
                    ans+=1
        
        return ans
