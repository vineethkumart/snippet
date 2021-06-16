/* Leetcode: https://leetcode.com/problems/house-robber/
 * A robber can't rob from consecutive houses
 * This is a dp problem, can be solved using bottom up and come up with that first
 *
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
 *
 * her we dont't need all the prev states but just 2 states. so 
 *
 * c = max(b, a+nums[i]);
 * a = b;
 * b = c;
 *
 * b is the answer finally
 */

class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.empty()) return 0;
            if (nums.size() == 1) return nums[0];
            int a = nums[0];
            int b = max(a, nums[1]);
            for (int i = 2; i < nums.size(); i++) {
                int c = max(a + nums[i], b);
                a = b;
                b = c;
            }
            return b;

        }
};

/* if the TC is modified with a circular condition, if its odd number then remove 0th item find max and n-1 item find max, reurn max of both
