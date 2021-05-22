#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int edit_distance(string s1, string s2)
{
    if (s1.empty()) return s2.length();
    if (s2.empty()) return s1.length();

    if (s1.at(0) == s2.at(0)) return edit_distance(s1.substr(1), s2.substr(1)); // no op required

    return 1 + min(
        edit_distance(s1.substr(1), s2.substr(1)),      // modify
        min(
        edit_distance(s1, s2.substr(1)),      // delete
        edit_distance(s1.substr(1), s2)       // add
        )
        );
}


int edit_distance_dp(string s1, string s2)
{
    int dp[s1.length()+1][s2.length()+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= s1.length(); i++) {
        dp[i][0] = i;
    }

    for (int i = 0; i <= s2.length(); i++) {
        dp[0][i] = i;
    }


    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int c(INT_MAX);
                c = min(c, dp[i][j-1]); // add
                c = min(c, dp[i-1][j-1]); // modify
                c = min(c, dp[i-1][j]); // remove

                dp[i][j] = 1+c;
            }
        }
    }

    return dp[s1.length()][s2.length()];
}
int main()
{
    string s1 = "sunday";
    string s2 = "saturday";

    cout << edit_distance_dp(s1, s2);
}



