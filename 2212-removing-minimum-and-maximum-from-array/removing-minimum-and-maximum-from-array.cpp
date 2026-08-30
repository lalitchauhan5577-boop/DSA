class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        // Make mn the smaller index and mx the larger index
        if (mn > mx)
            swap(mn, mx);

        // Option 1: remove both from front
        int fromFront = mx + 1;

        // Option 2: remove both from back
        int fromBack = n - mn;

        // Option 3: remove mn from front, mx from back
        int oneEach = (mn + 1) + (n - mx);

        return min({fromFront, fromBack, oneEach});
    }
};