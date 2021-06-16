#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cassert>


using namespace std;


int min_jump(int a[], int i, int n, int dp[])
{
    if (i >= n-1) return 0; // no more jumps required

    int& ans = dp[i];
    if (ans) return ans;

    ans = INT_MAX;

    for (int s = 1; s <= a[i]; s++) {
        ans = min(ans, 1 + min_jump(a, i+s, n, dp));
    }

    return ans;
}

int min_jump(int a[], int n)
{
    if (*a == 0) return -1;
    if (*a == n-1) return 1;

    int jumps(1);
    int steps = a[0];
    int mr = steps;

    for (int i = 1; i < n-1; i++) {
        mr = max(mr, i + a[i]);
        steps--;
        if (steps == 0) {
            jumps++;
            steps = mr - i;
            if (steps == 0) return -1; // cant go further
        }
    }

    return jumps;
}

int main()
{
    //int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    auto n = sizeof(a) / sizeof(*a);

    int dp[n];
    for (int i = 0; i < n-1; i++) dp[i] = INT_MAX - 10;
    dp[n-1] = 0;

   //cout << min_jump(a, 0, n, dp);
   
    // bottom up
    for (int i = n-2; i >= 0; i--) {
        for (int j = 1; j <= a[i]; j++) {
            if (i + j < n-1) {
                dp[i] = min(dp[i], 1 + dp[i+j]);
            } else {
                dp[i] = min(dp[i], 1);
            }
        }
    }

    cout << dp[0] << endl;
    cout << min_jump(a, n);
}
