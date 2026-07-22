class Solution {
  public:
    int check(vector<int> &nums){
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(i == 0) ans.push_back(nums[i]);
            if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
            ans[low] = nums[i];
        }
    }
    return n - ans.size();

}
    int minDeletions(vector<int>& nums) {
        return check(nums);
        
    }
};

