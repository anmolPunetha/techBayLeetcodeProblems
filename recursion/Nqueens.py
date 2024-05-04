class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans=[] # will store all the configurations
        grid=[]
        for i in range(n):
            s=[]
            for j in range(n):
                s.append(".")
            grid.append(s)
        
        def isSafeToPlaceQ(grid,rowIndex,colIndex):
            #check the upper col, the 2 upper diagonals
            #col
            row=rowIndex
            while row>=0:
                if grid[row][colIndex]=="Q":
                    return False
                row-=1

            #left diagonal
            row=rowIndex
            col=colIndex
            while row>=0 and col>=0:
                if grid[row][col]=="Q":
                    return False
                row-=1
                col-=1
            
            #right 
            row=rowIndex
            col=colIndex
            while row>=0 and col<n:
                if grid[row][col]=="Q":
                    return False
                row-=1
                col+=1

            return True


        def helper(rowIndex, grid):
            #base case
            if rowIndex==n:
                res=[] # n strings representing each row
                for i in range(n):
                    res.append("".join(grid[i]))
                ans.append(res)
                return
            
            #main structure
            for colIndex in range(0, n):
                #check for the place rowIndex,colIndex
                if isSafeToPlaceQ(grid,rowIndex,colIndex):
                    grid[rowIndex][colIndex]="Q"
                    #add your index(3) to your dict
                    helper(rowIndex+1,grid)
                    grid[rowIndex][colIndex]="."
                    #remove/unmark your index(3) from your dict

        helper(0,grid)
        return ans

# res=["...Q", "..Q."]
# ans=[["...Q", "..Q."], ["...Q", "..Q."], ]
# . . Q .->..Q.
