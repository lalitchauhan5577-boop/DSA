class Solution {
public:

    int f(int m, int n,
          vector<vector<int>>& obstaclegrid,
          vector<vector<int>>& dp) {

        if (m < 0 || n < 0)
            return 0;

        // Obstacle
        if (obstaclegrid[m][n] == 1)
            return 0;

        // Starting point
        if (m == 0 && n == 0)
            return 1;

        // Already calculated
        if (dp[m][n] != -1)
            return dp[m][n];

        // Come from top
        int left = f(m - 1, n, obstaclegrid, dp);

        // Come from left
        int right = f(m, n - 1, obstaclegrid, dp);

        return dp[m][n] = left + right;
    }

    int uniquePathsWithObstacles(
        vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};