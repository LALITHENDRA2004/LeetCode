class Solution {
public:
    int find(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(amount == 0) return 1;
        if(i == 0) {
            if(amount % coins[i] == 0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int pick = 0;
        if(coins[i] <= amount) pick = find(i, amount - coins[i], coins, dp);
        int notPick = find(i - 1, amount, coins, dp);
        return dp[i][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return find(coins.size() - 1, amount, coins, dp);
    }
};