// This takes mn time and space
//
// But this can be solved using Suffix Tree in 



#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;


int lcs(string s1, string s2, int res)
{
    if (s1.empty() || s2.empty()) return res; // max found so far

    if (s1.at(0) == s2.at(0)) {
        res = lcs(s1.substr(1), s2.substr(1), res+1); // got a match, increment result
        // we need continuous matches hence this way, when there is a mismatch, will set res to 0 again back
    }

    res = max(res,  // max so far
              max(lcs(s1.substr(1), s2, 0),  // new match 
              lcs(s1, s2.substr(1), 0)));    // new match
    return res; // return max length
}

int lcs_dp(string s1, string s2)
{
    const auto& m = s1.length();
    const auto& n = s2.length();

    int sol[m+1][n+1];
    memset(sol, 0, sizeof(sol));

    int mx(0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[i-1]) sol[i][j] = 1 + sol[i-1][j-1];
            mx = max(mx, sol[i][j]);
            // else no solution 0
        }
    }

    return mx;
}


int main()
{
    string X = "GeeksforGeeks";
    string Y = "GeeksQuiz";
    int res(0);
    cout << lcs(X, Y, res);

    cout << endl << lcs_dp(X, Y);

    return 0;
}
