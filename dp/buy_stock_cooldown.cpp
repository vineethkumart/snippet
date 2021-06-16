// Buy stock with a cooldown, can't buy the next day that you sold the stock.
// Top down with Memo is best here.
//
class Solution {
public:
    int p(vector<int>& prices, int i, int dp[]) 
    {
        if (i < 0) return 0;
        if (dp[i]) return dp[i];
        
        int& ans = dp[i];
        
        int x(0);
        // Look at this. Had it been no cooldown, we don't have to do this for all < elements but only with the smallest element.
        for (int k = 0; k < i; k++) {
            if (prices[k] < prices[i]) {
                x = max(x, (prices[i] - prices[k] + p(prices, k-2, dp))) ;
            }
        }
        
        ans = max(x,
                  p(prices, i-1, dp));
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()];
        memset(dp, 0, sizeof(dp));
        return p(prices, prices.size()-1, dp);
    }
};


/* Complexity analysis
 *
 * T(n) = T(n-1) + nT(n-1) // worst case
 * This usually takes n2^n complexity but here T(n-1) can be subst with n as we are computing T(n) only once
 * hence 
 * T(n) = n + n*n ==> O(n2)
 */
