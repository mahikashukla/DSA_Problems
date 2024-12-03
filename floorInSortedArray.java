class Solution {

    static int findFloor(int[] arr, int k) {
        // write code here
        int target;
        int n=arr.length;
        int low=0;
        int high = n-1;
        int ans= -1;
        
        while(low <= high) {
            int mid = low+(high-low)/2; //in order to avoid overflow
            if(arr[mid] <= k) {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
}
