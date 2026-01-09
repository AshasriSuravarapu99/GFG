class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dif(n);
        
        dif[0] = 0;
        dif[1] = abs(height[0]-height[1]);
        
        for(int i = 2; i<height.size(); i++){
            int a = abs(height[i]-height[i-2])+ dif[i-2];
            int b = abs(height[i]-height[i-1])+ dif[i-1];
            dif[i] = min(a,b);
        }
        return dif[n-1];
        
    }
};