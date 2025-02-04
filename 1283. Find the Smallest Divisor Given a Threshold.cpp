class Solution {
public:
    int computeSum(vector<int>& nums, int d) {  
        int sum = 0;
        for (int num : nums) {
            sum += (num + d - 1) / d;  
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (computeSum(nums, mid) <= threshold) { 
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        return low;
    }
};
