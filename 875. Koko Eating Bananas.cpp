#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int pile : piles) {
            maxi = max(maxi, pile);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int mid) {
        long long totalH = 0;  
        for (int pile : piles) {
            totalH += (pile + mid - 1) / mid;  
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;  
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; 
    }
};
