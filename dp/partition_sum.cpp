// partition a set into equal sum substes. Return true if possible else false
// leetcode: https://leetcode.com/problems/partition-equal-subset-sum/ 

class Solution {
    public:
        bool part(int i, int sum, int cs, vector<int>& nums, vector<vector<int>>& dp)
        {
            if (i >= nums.size()) return false;
            if (cs == sum - cs) return true;
            if (cs > sum-cs) return false;

            int& ans = dp[i][cs];
            if (ans != -1) return ans;

            // pick i and check
            cs += nums[i];
            if (part(i+1, sum, cs, nums, dp)) return (ans = true);
            // dont pick and check
            cs -= nums[i];
            if (part(i+1, sum, cs, nums, dp)) return (ans = true);

            return (ans = false);
        }

        bool canPartition(vector<int>& nums) {
            int sum(0);
            for (auto i : nums) sum += i;
            vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
            return part(0, sum, 0, nums, dp);
        }
};
