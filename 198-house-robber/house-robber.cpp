class Solution {
public:

    int f(int index, vector<int>& nums, vector<int>& dp) {
        // Base case
        if (index < 0)
            return 0;

        if (index == 0)
            return nums[0];

        // Already calculated
        if (dp[index] != -1)
            return dp[index];

        // Pick current house
        int pick = nums[index] + f(index - 2, nums, dp);

        // Don't pick current house
        int notPick = f(index - 1, nums, dp);

        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return f(n - 1, nums, dp);
    }
};