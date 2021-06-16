/*
 * There are many variants:
 * 1. Single Transaction
 * 2. Unlimited Transaction
 * 3. Atmost K Transaction
 * 4. Exactly K transaction
 * 5. With Cool down
 */

#include <iostream>
#include <algorithm>

using namespace std;

int single_buy(int a[], int n)
{
    // Simple variant, keep the small element on left and try selling on every day
    int m = a[0];
    int ans(0);
    for (int i = 1; i < n; i++) {
        if (a[i] < m) m = a[i];
        ans = max(ans, a[i] - m);
    }

    return ans;
}

int infinite_buy(int a[], int n)
{
    int ans(0);
    int i = 0;
    int b = 0;

    while (i < n-1) {
        while (i < n-1 && a[i] >= a[i+1]) i++;
        b = i;
        while (i < n-1 && a[i+1] >= a[i]) i++;
        ans += a[i] - a[b];
    }

    return ans;
}

int k_buy(int a[], int n, int k)
{
    // T(n, k) = max(T(i, k-1) + profit(i,n), T(n-1, k)); where i the index where a[i] is minimum
    // This can be easily solved top down or bottom up, complexity is N2K as you have to find the minimum every time
    // Can be improved with a tweak
    // let's solve it bottom up, top down is trivial
    int dp[n][k+1];
    memset(dp, 0, sizeof(dp));

    for (int t = 1; t <= k; t++) {
        for (int i = 1; i < n; i++) {
            int mx(INT_MIN);
            for (int k = 0; k < i; k++) {
                mx = max(mx, dp[k][t-1] + a[i] - a[k]);
            }
            dp[i][t] = max(dp[i-1][t], mx);
        }
    }

    return dp[n-1][k];


    // this takes n2K time can do in nk time with an observation as follows
}

int k_buy_opt(int a[], int n, int k)
{
    for (int t = 1; t <= k; t++) {
        int mp(INT_MIN);
        for (int i = 1; i < n; i++) {
            mp = max(mp, dp[i-1][t-1] - p[i-1]); // max profit so far - sell day price where you got max profit, you can now add todays sell price and get max
            dp[i][t] = max(dp[i-1][t], a[i] + mp)
        }
    }

    // now the complexity is nk
}

int main()
{
    int s[] = {7,1,5,3,6,4};
    int n = sizeof(s) / sizeof(*s);

    cout << single_buy(s, n) << endl;
    cout << infinite_buy(s, n) << endl;
    cout << k_buy(s, n, 2) << endl;
}


