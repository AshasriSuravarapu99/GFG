class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int  n = arr.size();
        stack<int>s;
        
        int res = 0;
        
        for(int i = 0; i < n; i++){
            
            while(!s.empty() && s.top() > arr[i]){
                s.pop();
            }
            
            s.push(arr[i]);
            res+=s.size();
            
        }
        
        return res;
        
    }
};