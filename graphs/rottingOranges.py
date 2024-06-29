class Solution:
    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #insert rotten oranges as inital sources
        #apply bfs and get the number of levels/minutes
        #since its bfs, so the count is min
        #if et at end, any orange is unrotten, return -1
        dx=[-1,0,1,0]
        dy=[0,1,0,-1]
        q=deque() # deque of list of size of 2[x,y]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==2:
                    q.append([i,j])
                
        ans=0
        while len(q)>0:
            n  = len(q)
            ans+=1
            while n>0:
                f = q.popleft()
                row=f[0]
                col=f[1]
                for k in range(4):
                    new_row = row+dx[k]
                    new_col = col+dy[k]
                    if new_row<0 or new_col<0 or new_row>=len(grid) or new_col>=len(grid[0]) or grid[new_row][new_col]!=1:
                        continue
                    #i get a fresh orange
                    grid[new_row][new_col]=2
                    q.append([new_row,new_col])
                n-=1

        flag = True # all are zeroes assumption    
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    return -1
                elif grid[i][j]==2:
                    flag=False
                

        if flag==True:
            return 0
        return ans-1
