class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0, 0, 0};

        for (int x : stones) {
            c[x % 3]++;
        }

        // Stones divisible by 3 don't change the remainder.
        // They can be used safely only when there are other moves available.
        if (c[0] % 2 == 0) {
            return c[1] > 0 && c[2] > 0;
        }

        // Odd number of 0-mod-3 stones
        return abs(c[1] - c[2]) > 2;
    }
};