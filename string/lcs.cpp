#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int lcs(string s1, string s2)
{
    if (s1.empty() || s2.empty()) return 0;

    if (s1.at(0) == s2.at(0)) {
        return 1 + lcs(s1.substr(1), s2.substr(1));
    }

    return max(lcs(s1, s2.substr(1)), lcs(s1.substr(1), s2));
}


int lcs_dp(string s1, string s2)
{
    int dp[s1.length()+1][s2.length()+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= s1.length(); i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= s2.length(); i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[s1.length()][s2.length()];
}


int main()
{
    string s1 = "abxycdedf";
    string s2 = "axbycd";

    cout << lcs(s1, s2);
    cout << lcs_dp(s1, s2);
}
