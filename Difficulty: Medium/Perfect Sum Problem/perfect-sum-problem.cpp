class Solution {
public:

    vector<vector<int>> dp;

    int find(int i, vector<int>& arr, int tot, int target) {

        if (i < 0) {
            return (tot == target);
        }

        if (dp[i][tot] != -1)
            return dp[i][tot];

        int take = 0;

        if (tot + arr[i] <= target) {
            take = find(i - 1, arr, tot + arr[i], target);
        }

        int notTake = find(i - 1, arr, tot, target);

        return dp[i][tot] = take + notTake;
    }

    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        dp.resize(n, vector<int>(target + 1, -1));

        return find(n - 1, arr, 0, target);
    }
};