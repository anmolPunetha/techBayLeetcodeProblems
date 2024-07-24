class Solution {
public:
    void dijsktra(int source, vector<vector<pair<int,int>>>&graph, vector<int>&distances){
        distances[source]=0;
        set<pair<int,int>>s;
        s.insert({0, source});
        while (!s.empty()){
            //node out
            auto p = *(s.begin()); //p will be pair, first val as dist and second as node
            s.erase(s.begin());
            int node=p.second;
            int dist_till_node = p.first;
            //check on its nbrs
                //if u get a lesser distance for a nbr,
                    //remove the entitiy if in the set
                    //add the new entry in the set
                    //update the distance vector
            
            for (auto nbrPair: graph[node]){
                int nbr=nbrPair.first;
                int nbr_wt=nbrPair.second;

                int new_dist = dist_till_node+nbr_wt;
                if (new_dist<distances[nbr]){
                    pair<int,int> old_entry = {distances[nbr], nbr};
                    //remove if found
                    if (s.find(old_entry)!=s.end()){
                        s.erase(old_entry);
                    }
                    //insert the new pair in the set
                    s.insert({new_dist,nbr});
                    distances[nbr]=new_dist;
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>distances(n+1, INT_MAX);
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0;i<times.size();i++){
            int from = times[i][0];
            int to = times[i][1];
            int wt = times[i][2];
            graph[from].push_back({to,wt});
        }
        dijsktra(k, graph, distances);
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(distances[i]==INT_MAX){
                return -1;
            }
            ans=max(ans, distances[i]);
        }
        return ans;
    }
};

//node->list of neighbors
//node->(nbr1,wt), (nbr2,wt)....
//vector<vector<pair<int,int>>>graph v[node]->list of nbrs
//v[node][i]->nbr->first entry of the pair, ->second entry will be the weight
