class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi , arr[i][1]);
        }
        vector<int>v(maxi+1, 0);
        for(int i = 0; i < arr.size(); i++){
            v[arr[i][0]-1]++;
            v[arr[i][1]]--;
        }
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};