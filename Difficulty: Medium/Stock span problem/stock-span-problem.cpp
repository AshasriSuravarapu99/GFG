class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int,int>>s;
        s.push({arr[0], 0});
        vector<int>ans(n,-1);
        for(int i = 0; i < n; i++){
            while(!s.empty()){
                if(s.top().first > arr[i]){
                    ans[i]  = i - s.top().second;
                    break;
                }
                else s.pop();
            }
            s.push({arr[i],i});
            if(ans[i] == -1) ans[i] = i+1;
        }
        return ans;
    }
};