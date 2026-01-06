class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        // int ans = INT_MIN;
        int ans = 0;
        for(int i=0;i<k;i++){
            ans^=arr[i];
        }
        int val = ans; 
        for(int j = k; j < arr.size(); j++){
            val^=arr[j];
            val^=arr[j-k];
            ans = max(ans,val);
            
        }
        return ans;
        
        
    }
};