

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int K = 1024;

        auto molqaviren = grid;

        vector<vector<vector<char>>> dp(
            m, vector<vector<char>>(
                n, vector<char>(K, 0)
            )
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int val = grid[i][j];

                for (int x = 0; x < K; x++) {
                    if (i > 0 && dp[i - 1][j][x]) {
                        dp[i][j][x ^ val] = 1;
                    }

                    if (j > 0 && dp[i][j - 1][x]) {
                        dp[i][j][x ^ val] = 1;
                    }
                }
            }
        }

        for (int x = 0; x < K; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return -1;
    }
};
