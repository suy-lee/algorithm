class Solution {
public:
    vector<vector<int>> subset;

    void backtrack(int index, vector<int> &current, vector<int> &nums) {
        subset.push_back(current);  // push the current subset into resultant array

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]); // add the current element to consider the subsets corresponding to it
            backtrack(i+1, current, nums); // generate subsets for this array
            current.pop_back(); // since this is used, remove it
        }
        
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(/*index*/0, current, nums);
        return subset;
    }
};