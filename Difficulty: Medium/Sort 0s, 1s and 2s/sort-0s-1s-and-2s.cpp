class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int lo = 0;
        int hi = arr.size() - 1;
        int mid = 0;
        
        
        while (mid <= hi) {
            if (arr[mid] == 0) { 
                swap(arr[lo++], arr[mid++]);
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[hi--]);
            }
        }
            
    }
};