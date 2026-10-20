
class Solution {
    bool isRotation(const vector<int>& a,
                    const vector<int>& target,
                    int start, int k) {
        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (target[start + i] == target[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int x = a[start + i % k];

            while (j > 0 && x != target[start + j]) {
                j = lps[j - 1];
            }

            if (x == target[start + j]) {
                j++;
            }

            if (j == k) return true;
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};