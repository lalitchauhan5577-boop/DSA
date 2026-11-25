
class Solution {
public:
    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ull> h(n + 1, 0), p(n + 1, 1);

        const ull base = 47;

        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * base + nums[i];
            p[i + 1] = p[i] * base;
        }

        auto check = [&](int len) {
            unordered_map<ull, int> mp;

            for (int i = 0; i + len <= n; i++) {
                ull hash = h[i + len] - h[i] * p[len];
                mp[hash]++;
            }

            for (auto &it : mp) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
