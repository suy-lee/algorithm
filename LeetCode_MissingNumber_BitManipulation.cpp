class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};
