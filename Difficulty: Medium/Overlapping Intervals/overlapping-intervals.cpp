class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        // Code here
        
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1; i < intervals.size(); i++)
        {
            int j = ans.size()-1;
            int start = ans[j][0];
            int end = ans[j][1];
            if(intervals[i][0] >= start && intervals[i][0] <= end){ 
                ans.pop_back();
                int e = max(intervals[i][1],end);
                ans.push_back({start,e});
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};