class Solution {
public:
    bool canNumBePlaced(char num, int ri, int ci, vector<vector<char>>& board){
        //row,col,subgrid
        //row
        for(int j=0;j<9;j++){
            if(board[ri][j]==num)return false;
        }

        //col
        for(int i=0;i<9;i++){
            if(board[i][ci]==num)return false;
        }

        //subgrid
        int sr=(ri/3)*3;
        int sc=(ci/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==num)return false;
            }
        }
        return true;
    }
    bool helper(int rowIndex, int colIndex, vector<vector<char>>& board){
        //base case
        if(rowIndex==9){
            return true; //i have found a valid solution
        }

        if(colIndex==9){
            return helper(rowIndex+1, 0, board);
        }

        //main structure
        if(board[rowIndex][colIndex]!='.'){ //pre filled cell
            return helper(rowIndex, colIndex+1, board);
        }

        //i have 1-9 options
        for(char num='1';num<='9';num++){
            if(canNumBePlaced(num,rowIndex,colIndex,board)){
                board[rowIndex][colIndex]=num;
                bool res=helper(rowIndex, colIndex+1, board);
                if(res==true)return true;
            }
        }
        board[rowIndex][colIndex]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0,0,board);
    }
};
