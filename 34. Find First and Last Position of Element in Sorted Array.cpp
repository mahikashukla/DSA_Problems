class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Helper function to find the first occurrence
        auto findFirst = [&](int target) -> int {
            int low = 0, high = nums.size() - 1, first = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) {
                    first = mid;
                    high = mid - 1; // Move left to find earlier occurrences
                } else if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return first;
        };
        
        // Helper function to find the last occurrence
        auto findLast = [&](int target) -> int {
            int low = 0, high = nums.size() - 1, last = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) {
                    last = mid;
                    low = mid + 1; // Move right to find later occurrences
                } else if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return last;
        };

        // Find the first and last positions
        int first = findFirst(target);
        if (first == -1) {
            return {-1, -1}; // Target not found
        }
        int last = findLast(target);
        return {first, last};
    }
};
