/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void solve(Node* root, long long currSum, int k,
           unordered_map<long long,int>& mp, int &count) {
    
    if(root == NULL)
        return;
    currSum += root->data;
    if(currSum == k)
        count++;

    if(mp.find(currSum - k) != mp.end())
        count += mp[currSum - k];
    mp[currSum]++;
    solve(root->left, currSum, k, mp, count);
    solve(root->right, currSum, k, mp, count);

    mp[currSum]--;
}

class Solution {
  public:
    int countAllPaths(Node *root, int k) {
        
        unordered_map<long long,int> mp;
    int count = 0;

    solve(root, 0, k, mp, count);

    return count;
        
        
    }
};