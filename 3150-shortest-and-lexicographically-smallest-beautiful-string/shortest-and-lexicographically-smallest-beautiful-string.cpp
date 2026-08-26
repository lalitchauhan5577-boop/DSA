class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // Shrink while we have more than k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                // Remove leading zeroes while keeping k ones
                int temp = left;
                while (temp <= right && s[temp] == '0')
                    temp++;

                int len = right - temp + 1;
                string cur = s.substr(temp, len);

                if (len < minLen) {
                    minLen = len;
                    ans = cur;
                }
                else if (len == minLen && cur < ans) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};