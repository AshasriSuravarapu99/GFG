class Solution {
  public:
    bool check(long long val, vector<int> &arr){
        int n = arr.size();
        for(int i = 0; i < n; i++){
             if (val > LLONG_MAX / 2) return true;
            if(arr[i] < val) val+=(val - arr[i]);
            else{
                val -= (arr[i] - val);
                if(val < 0) return false;
            }
        }
        return true;
    }
    int find(vector<int>& arr) {
        long long l = 1 , h = 10000;
        int ans = 0;
        while(l <= h){
            long long mid =  l + (h - l) / 2;
            if(check(mid,arr)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return (int)ans;
    }
};