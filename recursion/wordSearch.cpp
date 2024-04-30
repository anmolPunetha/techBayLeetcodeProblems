class Solution {
public:
    int rows,cols;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int idx){
        //base-case
        if(idx==word.size()){
            return true;
        }

        //invalid call
        if(r<0 or c<0 or r>=rows or c>=cols or board[r][c]!=word[idx]){
            return false;
        }

        //main structure
        char ch=board[r][c];
        board[r][c]='.'; //just to make sure that this is marked for the future calls
        // bool op1=dfs(board,word,r+1,c,idx+1); //down call
        // bool op2=dfs(board,word,r,c+1,idx+1);  //right call
        // bool op3=dfs(board,word,r-1,c,idx+1);  //up call
        // bool op4=dfs(board,word,r,c-1,idx+1);  //left call
        for(int k=0;k<4;k++){
            int rr=r+dx[k], cc=c+dy[k];
            bool res=dfs(board,word,rr,cc,idx+1);
            if(res==true)return true;
        }

        //restore the letter
        board[r][c]=ch; //backtracking
        // return op1 || op2 || op3 || op4;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    //can be a possible start
                    bool ans=dfs(board, word, i, j, 0);
                    if(ans==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
