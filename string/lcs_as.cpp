/*
 * Given s1, s2. find the longest SA in s1 that has the longest SS of s2
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


int lca_dp(string s1, string s2)
{
    const auto m = s1.size();
    const auto n = s2.size();

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }


    // return the max possible
    int l(0);
    for (int i = 1; i <= m; i++) {
        l = max(l, dp[i][n]);
    }

    return l;
}

int main()
{
    string s1 = "bacdbdcd";
    string s2 = "abcd";

    /*
    dp_t dp(s1.length()+1, vector<int>(s2.length()+1, 0));

    int l(0);
    for (int i = 0; i < s1.length(); i++) {
        int v = lca(s1, s2, i, 0, dp);
        l = max(l, v);
    }

    cout << l;
    */

    cout << lca_dp(s1, s2);
}


