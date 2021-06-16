/*
 * Given s1, s2. find the longest SA in s1 that has the longest SS of s2
 * practice at: https://practice.geeksforgeeks.org/problems/find-length-of-longest-subsequence4905/1
*/


#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using dp_t = vector<vector<int>>;

// lca starting at i and j
int lca(string s1, string s2, int i, int j, dp_t& dp)
{
    if (j == s2.length()) return 0; // s2 processed completely
    if (i == s1.length()) return 0; // s1 is over

    int& result = dp[i][j];
    if (result) {
        return result;
    }

    if (s1[i] == s2[j]) {
        result = 1 + lca(s1, s2, i+1, j+1, dp);
    } else {
        result = lca(s1, s2, i, j+1, dp);
    }

    return result;
}

int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    int dp[N+1][M+1];
    memset(dp, 0, sizeof(dp));

    // dp[i][j] is length of longest sss of Y in X ending at i, j such that the substring ends at j

    int ans(0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // return max ss possible
    for (int i = 1; i <= M; i++) {
        ans = max(ans, dp[N][i]);
    }

    return ans;
}
