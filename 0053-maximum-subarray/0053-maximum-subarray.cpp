class Solution {
public:
    int globalMaxSum;
    
    int maxSub(vector<int> &nums, int n) {
        if (n == 1) return nums[0];
        int currMaxSum = max(nums[n-1], maxSub(nums, n-1) + nums[n-1]);
        globalMaxSum = max(currMaxSum, globalMaxSum);
        return currMaxSum;
    }
    int maxSubArray(vector<int>& nums) {
        globalMaxSum = nums[0];
        maxSub(nums, nums.size());
        return globalMaxSum;
    }
};