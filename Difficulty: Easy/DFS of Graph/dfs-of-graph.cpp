class Solution {
  public:
    vector<int>ans;
    void dfs(int n, vector<vector<int>>& adj, vector<int> &vis){
        ans.push_back(n);
        vis[n] = 1;
        
        for(auto it: adj[n]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        return ans;
        
    }
};