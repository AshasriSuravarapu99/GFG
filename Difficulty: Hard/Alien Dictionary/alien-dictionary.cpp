class Solution {
  public:
    int tot = 0;
    string topoSort(vector<vector<int>> & adj, vector<bool> &present){
        vector<int>indegree(26,0);
        for(int i = 0; i < 26; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < 26; i++){
            if(present[i]) tot++;
            if(present[i] && indegree[i] == 0) q.push(i);
        }
        
       string ans;
        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            
            ans.push_back(char(a+'a'));
            
            for(auto it : adj[a]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return ans;
    }
    string findOrder(vector<string> &words) {
        vector<vector<int>>adj(26);
        vector<bool> present(26, false);
         
         for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(),s2.size());
            int flag = 0;
            for(int i = 0; i < len; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && s1.size() > s2.size()) return "";
        }
        
        
        string topo = topoSort(adj,present);
        if(topo.size() < tot) return "";
        string ans = "";
        for(int i = 0; i < topo.size(); i++) ans+=topo[i];
        return ans;
        
    }
};