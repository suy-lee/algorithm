class Solution {
public:
    int dp[21][2001];
    
    int dfs(int index, vector<int> &nums, int &S, int sum) {
        // 1 is this is the path
        // 0 means not
        if (index == nums.size())
            return sum == S? 1 : 0;
        
        // if precalculated value is stored, return it
        if (dp[index][sum+1000] != -1) return dp[index][sum+1000];
        
        int count = 0;
        
        count += dfs(index+1, nums, S, sum+nums[index]);
        count += dfs(index+1, nums, S, sum-nums[index]);
        
        return dp[index][sum+1000] = count;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        
        return dfs(0, nums, target, 0);
    }
};