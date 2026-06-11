class Solution {
public:

    int maxi = 0;
    vector<vector<int>> dp;

    void find(int i, vector<int> &arr, int tot, int target) {

        if (target == tot) {
            maxi = max(maxi, tot);
            return;
        }

        if (i < 0) {
            maxi = max(maxi, tot);
            return;
        }

        if (dp[i][tot] != -1)
            return;

        dp[i][tot] = 1;

        if (arr[i] + tot <= target) {
            find(i - 1, arr, tot + arr[i], target);
        }

        find(i - 1, arr, tot, target);
    }

    int minDifference(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return arr[0];

        int sum = accumulate(arr.begin(), arr.end(), 0);

        int target = ceil(sum / 2.0);

        dp.resize(n, vector<int>(target + 1, -1));

        find(n - 1, arr, 0, target);

        return abs((sum - maxi) - maxi);
    }
};