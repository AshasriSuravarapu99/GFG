class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>dist(V,INT_MAX);
        vector<vector<pair<int,int>>>adj(V);
        for(int i =0; i < edges.size(); i++){
            int u  = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [wt,a] = pq.top();
            pq.pop();
            for(auto it : adj[a]){
                int v = it.first;
                int w = it.second;
                if(dist[v] > (wt+w)){
                    pq.push({wt+w,v});
                    dist[v] = wt+w;
                }
            }
        }
        return dist;
    }
};