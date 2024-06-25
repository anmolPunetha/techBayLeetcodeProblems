class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int r,c;

    void dfs(int i, int j, int org_color, int color, vector<vector<int>>& image){
        if(i<0 or j<0 or i>=r or j>=c or image[i][j]!=org_color){
            return;
        }

        image[i][j]=color;

        for(int k=0;k<4;k++){
            int ii=i+dx[k];
            int jj=j+dy[k];
            dfs(ii,jj,org_color,color,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //dfs first

        //source is given
        //save the color
        //go to the connected cells of the same color
        //if it is a valid cell, change its color to the given color
        r=image.size();
        c=image[0].size();
        int org_color = image[sr][sc];

        if(org_color==color)return image;
        
        dfs(sr, sc, org_color, color, image);
        return image;
    }
};
