class Solution {
public:
    int f(int i, vector<int>& dp) {
        if (i == 0) return 1;
        if (i == 1) return 1;

        if (dp[i] != -1)
            return dp[i];

        int left = f(i - 1, dp);
        int right = f(i - 2, dp);

        return dp[i] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};