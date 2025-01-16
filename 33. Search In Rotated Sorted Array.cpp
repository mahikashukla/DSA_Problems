class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow with (low + high) / 2

            if (nums[mid] == target) {
                return mid;
            }

            // Determine if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the left sorted portion
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Otherwise, the right half is sorted
            else {
                // Check if target lies within the right sorted portion
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
