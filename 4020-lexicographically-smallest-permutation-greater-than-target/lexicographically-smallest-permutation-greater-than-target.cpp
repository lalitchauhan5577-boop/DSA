class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string prefix = "";

        // Match target as long as possible
        int i = 0;
        for (; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] == 0)
                break;

            prefix += target[i];
            cnt[x]--;
        }

        // Backtrack: try to make the latest possible position larger
        for (int j = i; j >= 0; j--) {

            // If j is inside the matched prefix,
            // return that character to the available pool
            if (j < i) {
                cnt[target[j] - 'a']++;
                prefix.pop_back();
            }

            if (j == n)
                continue;

            int current = target[j] - 'a';

            // Find smallest available char > target[j]
            for (int c = current + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = prefix;

                    ans += char('a' + c);
                    cnt[c]--;

                    // Remaining chars should be smallest possible
                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};