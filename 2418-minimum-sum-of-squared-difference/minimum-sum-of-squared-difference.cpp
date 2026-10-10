class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1,
                               int k2) {

        int n = nums1.size();

        vector<int> diff(n);

        long long k = (long long)k1 + k2;

        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        // If we can make every difference 0
        long long totalDiff = 0;

        for (int x : diff) {
            totalDiff += x;
        }

        if (k >= totalDiff) {
            return 0;
        }

        // Binary search the smallest maximum difference
        int low = 0;
        int high = mx;

        while (low < high) {

            int mid = low + (high - low) / 2;

            long long required = 0;

            for (int x : diff) {
                if (x > mid) {
                    required += x - mid;
                }
            }

            if (required <= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        int level = low;

        // Reduce every difference > level down to level
        long long used = 0;

        for (int x : diff) {
            if (x > level) {
                used += x - level;
            }
        }

        long long remaining = k - used;

        long long ans = 0;

        for (int x : diff) {

            if (x > level) {
                x = level;
            }

            ans += 1LL * x * x;
        }

        // We still have some operations.
        // Reduce 'remaining' values from level -> level-1.
        if (level > 0) {
            for (int i = 0; i < n && remaining > 0; i++) {

                if (diff[i] >= level) {
                    ans -= 1LL * level * level;
                    ans += 1LL * (level - 1) * (level - 1);

                    remaining--;
                }
            }
        }

        return ans;
    }
};