#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


/*
 * Good Approach
 * -------------
 * Usually solved in DP approach
 *N2 nd N2 space but can be solved in N2 and constance space as well.
 NL where L is the longest palindrome possible
 mala y alam
 maam
*/

string longp(string s)
{
    int l(0);
    auto const& n = s.length();
    int st(0);

    // consider each point as middle and expand - Odd length
    for (int i = 0; i < n; i++) {
        int low = i-1;
        int high = i;

        while (low >=0 && high < n && s[low] == s[high]) {low--; high++;}
        l = max(l, high-low+1);
    }

    // even length
    for (int i = 1; i < n; i++) {
        int low = i-1;
        int high = i+1;

        while (low >=0 && high < n && s[low] == s[high]) {low--; high++;}
        l = max(l, high-low+1);

    }

    //return s.substr(st, l-1);
    cout << st << " " << l;
    return "";

}



int main()
{
    //string s = "forgeeksskeegfor";
    //string s = "iknowmalayalam";
    string s = "adccba";
    /*
     *  if we know if a smaller substring (i..j) is palindrome then we can find bigger string (i-1...j+1) 
     * dp[i][j] length of the longest palindrom in range i..j
     *  generate substrings on increasing order of length for this
     *  Once generated, dp[0][n-1] // max length possible is the answer
     *
     *  O(n2) time and space where n is the length of the original string not he string to be searched
     */
    auto const& n = s.length();
    int dp[n][n] = 0;
    
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n-1; i++) dp[i][i+1] = (s[i] == s[i+1] ? 1 : 0);

    // start generating from length 2. length 1  is computed already
    // if you think of substring its nothing but a transpose kind of a matrix

    int ml(0);
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                ml = len;
            }
        }
    }

    cout << ml;
    cout << longp(s);
    return 0;
}
