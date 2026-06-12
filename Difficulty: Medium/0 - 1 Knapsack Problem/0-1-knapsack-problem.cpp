class Solution {
  public:
    int find(int i, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp){
        if(i == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int nottake = find(i-1,val,wt,W,dp);
        int take = INT_MIN;
        if(wt[i] <= W){
           take = val[i] + find(i-1,val,wt,W-wt[i],dp);
        }
        
        return dp[i][W] = max(nottake,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n  = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return find(n-1,val,wt,W,dp);
        
    }
};