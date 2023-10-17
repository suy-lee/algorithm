class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int currAmount = 1; currAmount <= amount; currAmount++) {
            for (int j = 0; j < n; j++) { // traverse all coins
                if (coins[j] <= currAmount)
                    dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount-coins[j]]);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};