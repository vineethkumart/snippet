/*
 * This is a resource allocation problem
 * Given a set of resources and partition that into M partitions such that max job allocated to any such M is minimized.
 * You can partition contiguous elements only
 *
 * Input:
 N = 4
 A[] = {12,34,67,90}
 M = 2
Output:
113
Explanation:
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is
113, which is selected as the output.
 *
 */
 

/*
 * This can be solved recursively using memorization - DP
 * T(n,m) = T(n-1,m-1) + T(n-2,m-2) + ...
 * We have nm such sub problems and to find T(n,m) have to look at n sub problems hence complextiy is N2M
 * without memorization its exponential
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;
int find(int arr[], int s, int n, int m, vector<vector<int>>& dp)
{
    int a(0);
    if (m == 1) {
        for (int i = s; i < n; i++) a += arr[i];
        return a;
    }
    if (s >= n) return -1;
    if (n - s < m) return -1;
    int& ans = dp[s][m];
    if (ans) return ans;
    ans = INT_MAX;
    int alloc(0);
    for (int i = s; i < n; i++) {
        alloc += arr[i];        // for this student
        int sa = find(arr, i+1, n, m-1,dp);
        if (sa == -1) break; // allocation not possible
        ans = min(ans, max(alloc, sa));
    }

    return ans;
}



// Can we do better?
// This is a search problem, identify that. the answer will lie in between max page and sum of all pages for any M
// best case with M = n, max element and worst case with M = 1, the sum
//
// Also given an anwer can we verify it fast?
// We can try allocating given an answer and see how many students are required, if > m then not possible if < m possible
//
//
//Any place we can do linear, we can do binary
//

// This takes only NLogn Time against N2M -- much better

bool possible(int arr[], int n, int days, int m)
{
    int s(1);
    int sum(0);
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > days) {
            s++;
            sum = arr[i];
        }
    }
    return (s <= m);
}
//Function to find minimum number of pages.
int findPages(int arr[], int n, int m)
{
    int low = *max_element(arr, arr+n);
    int high = accumulate(arr, arr+n, 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        bool pred = possible(arr, n, mid, m); // the predicate
        if (pred) {
            // possible, tighten the answer
            high = mid -1;
        } else {
            // not possible relax the answer
            low = mid + 1;
        }
    }

    return low;
}


int main()
{
    int a[] = {12,34,67,90};
    int n = sizeof(a) / sizeof(*a);
    int m = 2;
    cout << findPages(a, n, m);

    return 0;
}


