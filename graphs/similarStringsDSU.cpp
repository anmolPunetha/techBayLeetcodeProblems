class Solution {
public:
    vector<int>par;
    int ans;
    
    bool check(int i, int j, vector<string>& s){
        int cnt=0;
        for(int k=0;k<s[i].size();k++){
            if(s[i][k]!=s[j][k])cnt++;
        }
        return cnt<=2;
    }
    
    int find(int node){
        if(par[node]==node){
            return node;
        }
        return par[node] = find(par[node]);
    }
    
    void union_(int i, int j,vector<string>& s){
        int pi=find(i);
        int pj=find(j);
        if(pi!=pj){
            if(check(i, j, s)){
                par[pi]=pj;
                ans--;
            }
        }
    }
    
    int numSimilarGroups(vector<string>& s) {
        int n=s.size();
        for(int i=0;i<n;i++)par.push_back(i);
        
        ans=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                union_(i, j, s);
            }
        }
        return ans;
    }
};
