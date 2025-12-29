class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int cnt = 0;
        int s1 = a.size() , s2 = b.size();
        int i = 0, j = 0;
        int ans = 0;
        while(i < s1 && j < s2 && cnt < k){
            if(a[i] <= b[j])
            {
                ans = a[i];
                i++;
            }
            else
            {
               ans = b[j];
               j++;
            } 
            cnt++;
            // if(cnt == k) return ans; 
        }
        if(cnt < k && i < s1){
            while(i < s1 && cnt < k){
                ans = a[i];
                i++;
                cnt++;
            }
        }
        else
        {
            while(j < s2 && cnt < k){
                ans = b[j];
                j++;
                cnt++;
                // if(cnt == k) return ans;
            }
        }
        return ans;
        
    }
};