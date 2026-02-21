class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int l = 0 , h = citations[n-1];
        
        int ans = 0;
        while(l <= h){
            int mid = l + (h - l)/2;
            int idx = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            if(n-idx >= mid){
                l = mid + 1;
                ans = mid;
            }
            else h = mid - 1;
            
        }
        return ans;
    }
};