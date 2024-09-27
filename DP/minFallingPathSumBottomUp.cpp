class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                //i,j=> min((i-1,j-1), (i-1,j), (i-1,j+1))
                int ans = matrix[i-1][j]; //op1
                if(j!=0){
                    ans=min(ans, matrix[i-1][j-1]); //op2
                }
                if(j!=n-1){
                    ans=min(ans, matrix[i-1][j+1]); //op3
                }
                matrix[i][j]+=ans;
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans, matrix[n-1][j]);
        }
        return ans;
    }
};
