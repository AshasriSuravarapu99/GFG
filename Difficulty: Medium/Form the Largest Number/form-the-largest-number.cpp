class Solution {
  public:
    bool static comp(string a , string b){
        return a+b > b+a;
    }
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string>s;
        for(int i = 0; i < n; i++){
            string v = to_string(arr[i]);
            s.push_back(v);
        }
        
        sort(s.begin(),s.end(),comp);
        
        // cout<<s.size();
        
        string ans = "";
        for(int i = 0; i < n; i++) ans+=s[i];
        
        if(ans[0] == '0') return "0";
        
        return ans;
        
    }
};