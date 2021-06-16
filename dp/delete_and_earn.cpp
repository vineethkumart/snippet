// https://leetcode.com/problems/delete-and-earn/ 
// Given numbers and you can choose a number and get its value but then can't choose num+1 and num-1. How much max value you can get
// Always start thinking from DP perspective for these problems 
//
// THis is a good one!

class Solution {
    public:
        int helper(vector<int> nums, int pos, vector<int>& dp){
            if(pos >= nums.size())
                return 0;

            if(dp[pos] != -1)
                return dp[pos];

            int temp = nums[pos];
            int i = pos;
            int sum = 0;

            // take all element nums[pos]
            for(;i<nums.size() && nums[i] == temp;i++)
                sum+=temp;

            // drop all temp+1
            int next_i = i;
            for(;next_i < nums.size() && nums[next_i] == temp+1; next_i++);

            int ans = max(sum + helper(nums,next_i), helper(nums,i));
            dp[pos] = ans;

            return ans;
        }

        int deleteAndEarn(vector<int>& nums) {
            vector<int> dp(nums.size()+1, -1);
            sort(nums.begin(),nums.end()); // sort the numbers to have an order and delete the next element
            // after sorting this reduces to pick/nopick type of DP

            // ie. you pick an eleement say 3, add its sum and find sol(next) or dont pick and sol(cur) return max. next will be from 5 onwards or anything > 4

            return helper(nums, 0, dp);
        }
};
