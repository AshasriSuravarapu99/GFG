class Solution {
  public:
    bool dfs(int i , int j, vector<vector<char>>&mat, string &word, vector<vector<int>> &vis, int idx){
        if(idx == word.size()) return true;
        if(i >= mat.size() || j >= mat[0].size() || i < 0 || j < 0) return false;
        if(vis[i][j] != 0) return false;
        if(mat[i][j] != word[idx]) return false;
        
        vis[i][j] = 1;
        bool left = dfs(i,j+1, mat,word,vis,idx+1);
        bool right = dfs(i,j-1, mat,word,vis,idx+1);
        bool btm = dfs(i+1,j, mat,word,vis,idx+1);
        bool top = dfs(i-1,j, mat,word,vis,idx+1);
        
        vis[i][j] = 0;
        
        return left || right || btm || top;
        
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int r = mat.size();
        int c = mat[0].size();
        
        for(int  i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                vector<vector<int>>vis(r,vector<int>(c,0));
                if(dfs(i,j,mat,word,vis,0)) return true;
            }
        }
        return false;
        
    }
};