class Solution {
public:
    using int64 = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        // Remove redundant denominations.
        vector<int> a;
        for (int x : coins) {
            bool redundant = false;
            for (int y : a) {
                if (x % y == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) a.push_back(x);
        }

        int m = a.size();

        auto count = [&](int64 x) {
            int64 ans = 0;

            function<void(int, int64, int)> dfs = [&](int idx, int64 l, int bits) {
                for (int i = idx; i < m; i++) {
                    int64 g = std::gcd(l, (int64)a[i]);
                    if (l > x / (a[i] / g)) continue; // LCM exceeds x / overflow guard
                    int64 nl = l / g * a[i];

                    if (bits % 2 == 0)
                        ans += x / nl;
                    else
                        ans -= x / nl;

                    dfs(i + 1, nl, bits + 1);
                }
            };

            dfs(0, 1, 0);
            return ans;
        };

        int64 lo = 1;
        int64 hi = (int64)a[0] * k;

        while (lo < hi) {
            int64 mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
