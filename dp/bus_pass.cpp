#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


// dpass to complete the journed from i'th day
// answer is when called with 0
int dpass(vector<int>& days, vector<int>& pass, int i, int dp[])
{
    if (i >= days.size()) return 0;

    auto isSafe = [&](int i )  -> bool{
        return (i >= 0 && i < days.size());
    };

    int& ans = dp[i];
    if (ans) return ans;

    int x = pass[0];
    int y = pass[1];
    int z = pass[2];

    if (isSafe(i+1))
        x += dpass(days, pass, i+1, dp);

    // skip to next week
    int j;
    for (j = i+1; (j < i + 7 && j < days.size()  && days[j] < days[i] + 7); j++);
    if (isSafe(j)) y += dpass(days, pass, j, dp);

    // skip to next month
    for (j = i+1; (j < i + 30 && j < days.size() && days[j] < days[i] + 30); j++);
    if (isSafe(j)) z += dpass(days, pass, j, dp);


    ans = min(x, min(y, z));
    return ans;
}


int main()
{
    vector<int> days{1,4,6,7,8,20};
    vector<int> pass{2,7,15};

    int dp[days.size()];
    memset(dp, 0, sizeof(dp));

    cout << dpass(days, pass, 0, dp); 
    return 0;
}
