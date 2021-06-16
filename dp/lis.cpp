class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; i++) dp[i] = 1;
        int ans(1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                ans = max(ans, dp[i]);
            }
        }
        
        return ans;
    }
};

/* COmplexity is n2 with extra n space */

/* Can we do better? 
 * [10,9,2,5,3,7,101,18]
 *
 * Here we need to remember min element that can possibly at a position i and if we keep minimum element then when a new element comes that element will contribute to increasing SS with min then it will c
 *
 *
 * 10 then when 9 comes, replace 10 with 9 as 9 is possibly the min element that can be at a seq of length 1 encountered so far
 * 9 , 2 comes replace 2
 * 2 5 push and now 3 comes, replace 5 with 3
 * 2 3 now say element > 3 , < 3 > 5 comes, then if greater than 3, there is always a ss of length 3(2,3,el) if its less than 3 no.
 *
 *
 * So we can use binary search to find the correct position to insert/replace do that and remember max len*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> pos;
    int len(0);
    for (auto i : nums) {
        auto itr = lower_bound(pos.begin(), pos.end(), i);
        if (itr == pos.end()) {
            pos.push_back(i);
            len++;
        } else {
            // replace
            pos[itr - pos.begin()] = i;
        }
    }

    return len;
}

