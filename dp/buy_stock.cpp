// Buy and sell Stock with K transactions or less

/*
 * k = 2
 * [6,1,3,2,4,7]
 * 1,3 -> 2,7: profit 7
 * T(n,k) = max(a[n] - a[i] + T(n-1, k-1), T(n-1, k)),
 * i.e sell on nth day by possibly trying to buy from all prev day and complete k-1 transaction
 * Or leve out nth day and do k transactions till n-1 days
 * Complexity: N2K
 * Can be improved by avoiding finding the inner loop, and hene Nk
 *
 *
 *
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        auto n = prices.size();
        int dp[n][k+1];
        memset(dp, 0, sizeof(dp));
        
        for (int t = 1; t <= k; t++) {
            int mp(INT_MIN);
            for (int i = 1; i < n; i++) {
                mp = max(mp, dp[i-1][t-1] - prices[i-1]);
                dp[i][t] = max(mp + prices[i], dp[i-1][t]);
            }
        }                       
        return dp[n-1][k];  
    }
};
