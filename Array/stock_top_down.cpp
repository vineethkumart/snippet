#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int mp(int K, int N, int A[], vector<vector<int>>& dp)
{
    if (N == 0 || K == 0) return 0; // buy and sell on day 0
    int & res = dp[K][N];
    if (res != INT_MIN) return res;

    int mx(INT_MIN);
    for (int i = 0; i <= N-1; i++) {
        if ((A[N] - A[i]) + mp(K-1, i, A, dp) > mx) {
            mx = (A[N] - A[i]) + mp(K-1, i, A, dp);
        }
    }

    res = max(mx, mp(K, N-1, A, dp));
    return res;
}

int maxProfit(int K, int N, int A[]) {
    vector<vector<int>> dp(K+1, vector<int>(N, INT_MIN));
    return mp(K, N-1, A, dp);
}

int main()
{
    int A[] = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(2, 6, A);
}
