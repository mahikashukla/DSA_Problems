class Solution {
public:
    int search(vector<int>& nums, int target, int low, int high) {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;

        if (target > nums[mid])
            return search(nums, target, mid + 1, high);
        else
            return search(nums, target, low, mid - 1); 
    }

    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};
