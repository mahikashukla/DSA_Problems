class Solution {
    public int findKthPositive(int[] arr, int k) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left)/2;
            //number of missing elements is less than k 
            if (arr[mid]-mid-1 < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left+k;
    }
}
