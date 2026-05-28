class Solution {
  public:
    bool dfs(int i,  vector<vector<int>> &adjList, vector<int> &vis){
        vis[i] = 2;
        for(auto it : adjList[i]){
            if(!vis[it]){
                if(dfs(it,adjList,vis) == true){
                    return true;
                }
            }
            else if(vis[it] == 2){
                return true;
            }
        }

        vis[i] = 1;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i,adjList,vis) == true){
                    return true;
                }
            }
        }
        return false;
        
    }
};