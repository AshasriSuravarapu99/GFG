class Solution {
  public:
    void dfs(int i, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st){
        vis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<int>>adj(V);
         for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        stack<int>st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
        
    }
};