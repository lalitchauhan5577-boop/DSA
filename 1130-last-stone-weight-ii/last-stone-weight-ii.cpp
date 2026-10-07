class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalSum = 0;
        for (int x : stones) {
            totalSum += x;
        }

        int k = totalSum / 2;

        // dp[target] = whether target sum is possible
        vector<bool> dp(k + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int target = k; target >= stone; target--) {
                dp[target] = dp[target] || dp[target - stone];
            }
        }

        for (int s1 = k; s1 >= 0; s1--) {
            if (dp[s1]) {
                return totalSum - 2 * s1;
            }
        }

        return 0;
    }
};