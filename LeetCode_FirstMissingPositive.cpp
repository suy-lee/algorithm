class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int hash = n + 1;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] >= hash) nums[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            idx = (nums[i] % hash) - 1;
            if (idx >= 0) nums[idx] += hash;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] / hash == 0) return i+1;
        }

        return hash;
    }
};
