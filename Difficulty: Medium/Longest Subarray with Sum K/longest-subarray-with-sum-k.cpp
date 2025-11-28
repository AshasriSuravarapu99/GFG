class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int>m;
        int ans = 0;
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum == k) ans = max(ans , i+1);
            else if(m.find(sum-k) != m.end())
            {
                ans = max(ans , i-m[sum-k]);
            }
            if(m.find(sum) == m.end()) m[sum] = i;
        }
        return ans;
    }
};