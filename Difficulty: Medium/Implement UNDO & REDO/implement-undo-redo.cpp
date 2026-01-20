class Solution {
  public:
    string ans = "";
    stack<char>s;
    void append(char x) {
        // append x into document
        ans+=x;
    }

    void undo() {
        // undo last change
        s.push(ans[ans.size()-1]);
        ans.pop_back();
    }

    void redo() {
        // redo changes
        if(!s.empty()){
            ans+=s.top();
            s.pop();
        }
    }

    string read() {
        return ans;
        // read the document
    }
};