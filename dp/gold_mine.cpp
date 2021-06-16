/* Given a matrix with gold coins inside it
 * A miner can move to Right, right top, right bottom. Whats the max he can collect starting from any row in the first column
 * 
 * */

/* Note here miner always move towards the right and hence we can use DP bottom up easily */


// { Driver Code Starts
// Initial Template for C++

class Solution{
public:
    int maxGold(int m, int n, vector<vector<int>> M)
    {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        int ans(0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                int a(0);
                if (j - 1 >= 0) {
                    a = max(a, dp[i][j-1]);
                    if (i - 1 >= 0)
                        a = max(a, dp[i-1][j-1]);
                    if (i + 1 < m)
                        a = max(a, dp[i+1][j-1]);
                }
                dp[i][j] = a + M[i][j];
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

/* Observations:
 * 1. ans can be max of any thing of max of last column
 * 2. Always check if its safe to get value and how to get value row major or column major form
 */


