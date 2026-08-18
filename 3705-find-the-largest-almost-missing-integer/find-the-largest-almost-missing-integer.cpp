class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int windows = n - k + 1;

        unordered_map<int, vector<int>> pos;

        // Store positions of every number
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = -1;

        for (auto& [x, indices] : pos) {
            int total = 0;
            int L = -1, R = -1;

            for (int i : indices) {
                // Windows of size k containing index i
                int l = max(0, i - k + 1);
                int r = min(i, windows - 1);

                if (L == -1) {
                    L = l;
                    R = r;
                }
                else if (l > R + 1) {
                    // Finish previous interval
                    total += R - L + 1;

                    L = l;
                    R = r;
                }
                else {
                    // Merge overlapping intervals
                    R = max(R, r);
                }
            }

            if (L != -1) {
                total += R - L + 1;
            }

            // x appears in exactly one subarray
            if (total == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};