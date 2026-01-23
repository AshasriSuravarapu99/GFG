class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i =0 ;i < n;i++){
            maxi = max(maxi,arr[i]);
        }
        int ans = 0;
        int cnt =0;
        int flag =-1;
        int res = INT_MIN;
        for(int i = 0;i < n;i++){
            if(arr[i] == maxi&&flag == -1){
                ans = cnt;
                cnt = 0;
                flag = 1;
            }
            else if(arr[i] == maxi && flag == 1){
                res = max(ans+cnt+1,res);
                ans = cnt;
                cnt = 0;
            }
            else cnt++;
        }
        res = max(ans+cnt+1,res);
        return res;
    }
};