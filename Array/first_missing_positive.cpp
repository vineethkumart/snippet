/*
 * Given array of numbers unsorted, find the first missing positive number
 * [-1,2,4,3,1,9] => 5
 */

int firstMissingPositive(vector<int>& nums) {
    // Array of numbers and need to find first missing +ve number
    // Say if nothing is missing and 1,2,..,n is present then next missing number if n+1
    // so the first missing number can be 1 to n+1 inclusive only

    // Use an additional array of size n+1 and when i is found < n+1 set the index to 1. scan the array and return first missing.
    // Idea is that we can use the same array to keep the numbers 1..n

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > n || nums[i] <= 0) continue;
        int idx = nums[i] - 1;
        assert(idx >= 0 && idx < n);
        if (idx == i) continue;

        // swap with idx
        if (nums[i] != nums[idx]) {
            swap(nums[i], nums[idx]);
            i--;
        }
    }

    for (int i = 0; i < n; i++) {
        int idx = nums[i] - 1;
        if (idx != i) return i + 1;
    }

    return n+1;
}
