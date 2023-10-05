class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int currAmount = 1; currAmount <= amount; currAmount++) {
            for (auto &coin: coins)
                if (coin <= currAmount)
                    dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount-coin]);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};