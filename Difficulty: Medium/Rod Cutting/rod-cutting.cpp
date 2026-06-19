class Solution {
  public:
  
    int fun(int i, int len, vector<int> &price, vector<vector<int>>& dp){
        
        if(len == price.size())
            return 0;
            
        if(i == price.size())
            return -1e9;
            
        if(dp[i][len] != -1)
            return dp[i][len];
            
        int pick = -1e9;
        
        if(len + (i + 1) <= price.size()){
            pick = price[i] +
                   fun(i, len + (i + 1), price, dp);
        }
        
        int notPick = fun(i + 1, len, price, dp);
        
        return dp[i][len] = max(pick, notPick);
    }
    
    int cutRod(vector<int> &price) {
        
        int n = price.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return fun(0, 0, price, dp);
    }
};