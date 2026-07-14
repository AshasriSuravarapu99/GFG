class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;

        priority_queue<int> pq;
        for (int x : arr)
            pq.push(x);

        long long ans = 0;

        while (k--) {
            int a = pq.top();
            pq.pop();

            if (a > 0)
                ans = (ans + a) % MOD;

            pq.push(a - 1);
        }

        return ans % MOD;
    }
};