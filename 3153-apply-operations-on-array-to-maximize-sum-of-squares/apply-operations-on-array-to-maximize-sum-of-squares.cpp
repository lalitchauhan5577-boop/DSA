class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;

        // Count how many numbers have each bit set
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (x & (1LL << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Construct k maximum numbers
        for (int i = 0; i < k; i++) {

            long long x = 0;

            // Take highest available bits first
            for (int bit = 30; bit >= 0; bit--) {

                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};