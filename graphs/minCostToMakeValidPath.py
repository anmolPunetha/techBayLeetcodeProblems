class Solution:
    def dijsktra(self, grid, distances):
        n,m=len(grid), len(grid[0])
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]

        min_heap = [[0,0,0]] # [w,i,j]
        distances[0][0]=0
        # looping until min_heap is empty 
        while min_heap:
            w,i,j = heapq.heappop(min_heap)
            print(w,i,j)
            for k in range(0,4):
                ii=i+dx[k]
                jj=j+dy[k]
                if ii>=0 and jj>=0 and ii<n and jj<m:
                    edge_wt=1
                    if grid[i][j]==k+1:
                        edge_wt=0
                    if distances[i][j] + edge_wt < distances[ii][jj]:
                        heapq.heappush(min_heap,[edge_wt,ii,jj])
                        distances[ii][jj]=distances[i][j] + edge_wt #new distance
        return

    def minCost(self, grid: List[List[int]]) -> int:
        n,m=len(grid), len(grid[0])
        distances=[]
        for i in range(0, n):
            distances.append([])
            for j in range(0, m):
                distances[-1].append(100000000)
        
        self.dijsktra(grid, distances)
        #print(distances)
        return distances[n-1][m-1]
