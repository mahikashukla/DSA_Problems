class Solution {
public:
    int countSplits(vector<int>& nums, int maxSumAllowed) {
        int splits = 1;  
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= maxSumAllowed) {
                currentSum += num;
            } else {
                splits++;          
                currentSum = num;  
            }
        }
        return splits;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());  
        int high = accumulate(nums.begin(), nums.end(), 0);  

        while (low <= high) {
            int mid = low + (high - low) / 2;  
            int splits = countSplits(nums, mid);

            if (splits > m) {
                low = mid + 1;  
            } else {
                high = mid - 1;  
            }
        }
        return low;
    }

    int findArray(vector<int>& nums, int n, int m) {
        if (m > n) return -1;  
        return splitArray(nums, m);
    }
};
