class Solution {
  public:
    bool fun(int i, vector<int> &arr,int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i == arr.size()){
            if(target == 0) return true;
            return false;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        bool a = false;
        if(target >= arr[i])  a = fun(i+1,arr,target-arr[i],dp);
        bool b = fun(i+1, arr,target,dp);
        
        return dp[i][target] = a || b;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(201,vector<int>(1e4,-1));
        return fun(0,arr,sum,dp);
    }
};