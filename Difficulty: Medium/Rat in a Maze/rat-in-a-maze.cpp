class Solution {
  public:
    void fun(int i, int j, string s, vector<vector<int>>& maze, vector<string> &ans,
    vector<vector<int>> &vis){
        
        int r = maze.size();
        int c = maze[0].size();
        
        if(i == r-1 && j == c-1){
            ans.push_back(s);
            return;
        }
        
        vis[i][j] = 1;
        
        if(i + 1 < r && (maze[i+1][j] == 1) && !vis[i+1][j]) {
            s+='D';
            fun(i+1,j,s,maze,ans,vis);
            s.pop_back();
        }
        if(j-1 >= 0 && maze[i][j-1] == 1 && !vis[i][j-1]){
            s += 'L';
            fun(i,j-1,s,maze,ans,vis);
            s.pop_back();
        }
        if(j + 1 < c && maze[i][j+1] == 1 && !vis[i][j+1]){
            s += 'R';
            fun(i, j + 1, s, maze, ans,vis);
            s.pop_back();
        }
        if(i - 1 >= 0 && maze[i-1][j] == 1 && !vis[i-1][j]){
            s += 'U';
            fun(i-1,j,s,maze,ans,vis);
            s.pop_back();
        }
        vis[i][j] = 0;
        return;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int r = maze.size();
        int c = maze[0].size();
        
        vector<string> res;
        if(maze[0][0] == 0 || maze[r-1][c-1] == 0) return res;
        
        vector<vector<int>> vis(r,vector<int>(c,0));
        fun(0,0,"",maze,res,vis);
        return res;
        
    }
};