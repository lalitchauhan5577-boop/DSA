
#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();

        // 1. Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // 2. Length 2 and unsorted is IMPOSSIBLE:
        // Proper substrings only have length 1, which cannot change character order.
        if (n == 2) {
            return -1;
        }

        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());

        // 3. 1 Operation: min at index 0 OR max at index n-1
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        // Check if min_char or max_char exists in the middle substring (s[1 ... n-2])
        bool min_in_middle = false;
        bool max_in_middle = false;

        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char) min_in_middle = true;
            if (s[i] == max_char) max_in_middle = true;
        }

        // 4. 3 Operations: max at front, min at back, and neither is in the middle
        if (s[0] == max_char && s[n - 1] == min_char && !min_in_middle && !max_in_middle) {
            return 3;
        }

        // 5. 2 Operations for all other cases
        return 2;
    }
};