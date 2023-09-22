class Solution {
public:
    int dp[21][2001];
    
    int dfs(vector<int> &nums, int index, int S, int sum) {
        if (index == nums.size()) {
            if (sum == S) return 1;
            else return 0;
        }
        
        if (dp[index][sum+1000] != -1) return dp[index][sum+1000];
        
        int count = 0;
        
        count += dfs(nums, index+1, S, sum+nums[index]);
        count += dfs(nums, index+1, S, sum-nums[index]);
        
        return dp[index][sum+1000] = count;     
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        
        return dfs(nums, 0, target, 0);
    }
};