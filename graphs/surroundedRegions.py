class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        #find border cells and dfs on that region to convert from o to 2
        #traversal:
            #0s->Xs
            #2s->0
        dx=[-1,0,1,0]
        dy=[0,1,0,-1]

        def dfs(r,c):
            if r<0 or c<0 or r>=len(board) or c>=len(board[0]) or board[r][c]=='X' or board[r][c]=='2':
                return
            
            #board[r][c] is a O for sure
            board[r][c]='2'

            for k in range(4):
                ii=r+dx[k]
                jj=c+dy[k]
                dfs(ii,jj)
            
            return

        for i in range(len(board)):
            for j in range(len(board[0])):
                if (i==0 or j==0 or i==len(board)-1 or j==len(board[0])-1) and (board[i][j]=='O'):
                    dfs(i,j)
                
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='O':
                    board[i][j]='X'
                elif board[i][j]=='2':
                    board[i][j]='O'

        
