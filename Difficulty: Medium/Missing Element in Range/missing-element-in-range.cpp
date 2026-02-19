class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        map<int,int>m;
        int n = arr.size();
        for(int i = 0; i < n; i++) m[arr[i]]++;
        vector<int>ans;
        for(int i = low; i <= high; i++){
            if(!m[i]) ans.push_back(i);
        }
        return ans;
    }
};