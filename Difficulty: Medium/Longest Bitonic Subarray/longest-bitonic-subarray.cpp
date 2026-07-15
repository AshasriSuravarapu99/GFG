class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        vector<int>pre(n,1);
        vector<int>suf(n,1);

        for(int i = 1; i < n; i++){
            if(arr[i] >= arr[i-1]) pre[i] = 1 + pre[i-1];
        }
        
        for(int i = n-2; i >=0 ; i--){
            if(arr[i] >= arr[i+1]) suf[i] = 1 + suf[i+1];
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (pre[i] + suf[i]) - 1);
        }
        return ans;
    }
};