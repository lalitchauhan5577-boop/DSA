
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins,
          vector<vector<int>>& dp) {

        if (amount == 0) return 0;

        if (ind == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int nottake = f(ind - 1, amount, coins, dp);

        int take = 1e9;
        if (coins[ind] <= amount) {
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        int ans = f(n - 1, amount, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};
