class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int n, int node, int color, vector<int>&visited){
        visited[node]=color;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                bool var=dfs(graph, n, nbr, 3-color, visited);
                if(!var)
                    return false;
            }
            else if(visited[nbr]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n, 0);
        //0-unvisited, 1-visited1, 2-visited2
        for(int i=0;i<n;i++){
            if(!visited[i]){ //for different component
                bool ans=dfs(graph, n, i, 1, visited);
                if(!ans)
                    return false;
            }
        }
        return true;
    }
};
