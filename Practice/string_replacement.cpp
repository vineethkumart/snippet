/*
Edit Distance
-------------
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:
Insert
Remove
Replace
*/

class Solution {
  public:
    int editDistance(string s, string t) {
       int dp[s.length()+1][t.length()+1];
       memset(dp, 0, sizeof(dp));
       // let dp[i][j] be min number of operations required to convert s(0->i) to t(0->j) inclusive
       // of i and j
       for (int j = 0; j <= t.length(); j++)
            dp[0][j] = j;
        for (int i = 0; i <= s.length(); i++)
            dp[i][0] = i;
        
       for (int i = 1; i <= s.length(); i++) {
           for (int j = 1; j <= t.length(); j++) {
               if (s[i-1] == t[j-1]) {
                   dp[i][j] = dp[i-1][j-1];
               } else {
                   int a = dp[i][j-1];
                   int m = dp[i-1][j-1];
                   int d = dp[i-1][j];
                   dp[i][j] = min(min(a,m),d) + 1;
               }
           }
       }
       
       return dp[s.length()][t.length()];
    }
    /*
    int editDistance(string s, string t, int* dp) {
        // base conditions
        if (s.empty() && t.empty()) return 0;
        if (s.empty()) return t.length();
        if (t.empty()) return s.length();
        
        // if characters match, consider the other half
        if (s[0] == t[0]) {
            return editDistance(s.substr(1), t.substr(1));
        }
        
        return 1 + min(min(
            editDistance(s.substr(1), t.substr(1)), // replace
            editDistance(s.substr(1), t)), // delete 
            editDistance(s, t.substr(1)));  //insert
    }*/
};
