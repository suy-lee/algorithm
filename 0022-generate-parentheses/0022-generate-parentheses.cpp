class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backtrack(ans, curr, 0, 0, n);
        return ans;
    }
    
    void backtrack(vector<string> &ans, string &curr, int leftCount, int rightCount, int n) {
        if (curr.size() == 2*n) {
            ans.push_back(curr);
            return;
        }
        
        if (leftCount < n) {
            curr.push_back('(');
            backtrack(ans, curr, leftCount+1, rightCount, n);
            curr.pop_back();
        }
        
        if (leftCount > rightCount) {
            curr.push_back(')');
            backtrack(ans, curr, leftCount, rightCount+1, n);
            curr.pop_back();
        }
    }
};