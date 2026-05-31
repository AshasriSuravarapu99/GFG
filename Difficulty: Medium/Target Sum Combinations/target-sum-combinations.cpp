class Solution {
  public:
    vector<vector<int>>ans;
    void fun(int i, vector<int> &arr, vector<int> comb, int target){
        if(i >= arr.size()){
            if(target == 0) ans.push_back(comb);
            return;
        }
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        if(target < 0) return;
        
        comb.push_back(arr[i]);
        fun(i,arr,comb,target-arr[i]);
        comb.pop_back();
        fun(i+1,arr,comb,target);
        
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<int>comb;
        fun(0,arr,comb,target);
        return ans;
        
    }
};