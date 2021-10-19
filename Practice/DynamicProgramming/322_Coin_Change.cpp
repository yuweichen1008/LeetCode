/*
Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 0; i <= amount; ++i)
            for(int j = 0; j < coins.size(); ++j)
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        return dp[amount] > amount? -1 : dp[amount];
    }
    // iterating over all combinations ( Optimized )
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int coin : coins)
            for(int j = coin; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coin] + 1);
            
        return dp[amount] > amount? -1: dp[amount];
    }
};