class Solution {
public:
    int n,m;
    int helper(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&mat){
        //base cases
        if(i==n){
            return 0;
        }
        if(j<0 or j==m){
            return INT_MAX-1000;
        }
        if (dp[i][j]!=INT_MIN)
            return dp[i][j];
        //main call
        int ans = mat[i][j];
        int left_diag_call = helper(i+1,j-1,dp,mat);
        int below_call = helper(i+1,j,dp,mat);
        int right_diag_call = helper(i+1,j+1,dp,mat);

        int min_option_for_rows_below=min(left_diag_call, min(below_call, right_diag_call));
        ans += min_option_for_rows_below;
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        //grid of that size to memoise
        vector<vector<int>>dp(n, vector<int>(m,INT_MIN));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            int result = helper(0,i,dp,matrix); //you can start from any element of that row
            ans=min(ans,result);
        }
        return ans;
    }
};
