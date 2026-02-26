class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        map<char,char>m;
        vector<int>vis(26,0);
        for(int i = 0; i < s1.size(); i++){
            if(m.find(s1[i]) == m.end() && vis[s2[i]-'a'] == 0){
                m[s1[i]] = s2[i];
                vis[s2[i]-'a'] = 1;
            }
            else if(m[s1[i]] != s2[i] || (m.find(s1[i]) == m.end() && vis[s2[i]-'a'] == 1)) return false;
        }
        return true;
        
    }
};