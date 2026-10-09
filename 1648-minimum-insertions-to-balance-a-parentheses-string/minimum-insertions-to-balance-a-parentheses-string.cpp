class Solution {
public:
    int minInsertions(string s) {
        int balance = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                balance++;
            }
            else {
                // Need two consecutive ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    // Already have both ')'
                    i++;
                }
                else {
                    // Only one ')' → insert another ')'
                    ans++;
                }

                // We need an opening '(' for these two ')'
                if (balance > 0) {
                    balance--;
                }
                else {
                    // Insert '(' before these ')'
                    ans++;
                }
            }
        }

        // Every remaining '(' needs two ')'
        ans += 2 * balance;

        return ans;
    }
};