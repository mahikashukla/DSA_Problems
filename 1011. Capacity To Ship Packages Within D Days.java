class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int minCap = 0;
        int maxCap = 0;

        for (int weight : weights) {
            minCap = Math.max(minCap, weight);
            maxCap += weight;
        }

        while (minCap < maxCap) {
            int mid = minCap + (maxCap - minCap) / 2;

            int sum = 0;
            int requiredDays = 1;

            for (int weight : weights) {
                if (sum + weight > mid) {
                    requiredDays++;
                    sum = 0;
                }
                sum += weight;
            }

            if (requiredDays > days) {
                minCap = mid + 1;  
            } else {
                maxCap = mid;  
            }
        }

        return minCap; 
    }
}
