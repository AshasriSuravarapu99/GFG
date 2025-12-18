class Solution {
  public:
    bool static comp(int a,int b)
    {
        if(a%2 != 0 && b%2!=0) return a>b;
        else if(a%2 == 0 && b%2 ==0) return a<b;
        else if(a%2 !=0 && b%2 == 0) return true;
        return false;
    }
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),comp);
    }
};