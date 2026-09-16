class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        // dp[i][j] = number of ways to draw j segments
        // using points 0...i

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i < n; i++) {

                // Add dp[i-1][j-1] to prefix sum
                sum = (sum + dp[i - 1][j - 1]) % MOD;

                // Don't use point i as the end of a new segment
                dp[i][j] = dp[i - 1][j];

                // Use point i as the end of a segment
                dp[i][j] = (dp[i][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};