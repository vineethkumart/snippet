/* Given an array of coins and an amount.
 * How many minimum coins required to make the amount
 * if not possible return -1 
 * https://leetcode.com/problems/coin-change/
 *
 * */


int coins(vector<int>& coins, int amount)
{
    int n = coins.size();
    int dp[n+1][amount+1];
    memset(dp, 0, sizeof(dp));

    // base condition, if you have 0 coins you can't make up any amount
    for (int i = 0; i <= amount; i++) {
        dp[0][i] = INT_MAX;
    }

    dp[0][0] = 0; // 0 coins and 0 amount, 0 ways

    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amount; a++) {
            if (a - coins[i-1] < 0 || dp[i][a-coins[i-1]] == INT_MAX) {
                // no solution to the subproblem, if we choose ith element
                dp[i][a] = dp[i-1][a];
            } else {
                dp[i][a] = min (1 + dp[i][a-coins[i-1]], dp[i-1][a]);
            }
        }
    }

    return dp[n][amount];
}

// Space optimized version
// We need only previous state answert for the current state. ie i depends only on i-1


int coins_opt(vector<int>& coins, int amount)
{
    usigned int dp[amount+1] = UINT_MAX;
    dp[0] = 0;

    for (int a = 0; a <= amount; a++) {
        for (int i = 0; i < coins.size(); i++) {
            if (a - coins[i] >= 0 && dp[a - coins[i]] != UINT_MAX)
                dp[a] = min(dp[a], 1 + dp[a - coins[i]]);
        }
    }

    return dp[amount];
}



