class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            if (nums[low] != nums[low + 1])
                return nums[low];

            if (nums[high] != nums[high - 1])
                return nums[high];

            low += 2;
            high -= 2;
        }

        return nums[low];
    }
};