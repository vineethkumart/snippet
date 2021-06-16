int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i-1] >= 0)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w- wt[i-1]]); 
            else 
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}


// NOTE:
// This can be optimized with linear storage, but see the pattern
// dp[w] depends on dp[w-] of previous i not current i. hence we need to compute in reverse
