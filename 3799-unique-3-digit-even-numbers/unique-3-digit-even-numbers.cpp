class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        // Count how many times each digit appears
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Hundreds digit
        for (int first = 1; first <= 9; first++) {
            if (freq[first] == 0) continue;

            freq[first]--;

            // Tens digit
            for (int second = 0; second <= 9; second++) {
                if (freq[second] == 0) continue;

                freq[second]--;

                // Units digit must be even
                for (int third : {0, 2, 4, 6, 8}) {
                    if (freq[third] > 0) {
                        ans++;
                    }
                }

                freq[second]++;
            }

            freq[first]++;
        }

        return ans;
    }
};