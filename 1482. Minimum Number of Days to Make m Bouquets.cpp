class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int days, int m, int k) {
        int count = 0, bouquets = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                count++;  
                if (count == k) {  
                    bouquets++;
                    count = 0;  
                }
            } else {
                count = 0;  
            }
        }
        
        return bouquets >= m;  
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = 1LL * m * k;
        if (totalFlowersNeeded > bloomDay.size()) return -1;  

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                high = mid;  
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};
