class Solution {
public:
    int find(int x,vector<int>&parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    void union_(int x, int y,vector<int>&parent){
        int p1=find(x,parent);
        int p2=find(y,parent);
        if(p1!=p2)parent[p1]=p2;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>parent(n);
        int ans=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    union_(i,j,parent);
            }
        }
        for(int i=0;i<n;i++) 
            if(parent[i] == i) ans++;
        return n-ans;
    }
};
