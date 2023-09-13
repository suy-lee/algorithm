class Solution {
public:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &curr, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if (target < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, curr, ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, ans);
        return ans;
    }
};