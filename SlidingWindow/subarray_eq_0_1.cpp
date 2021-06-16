#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Pattern: using prefix array
 * Find largest window with a given sum. +ve and -ve numbers
 *
 * If its only +ve, we can shrink window with invariant to find
 *
 * Now this is same as storing the invarint in a map and looking out for a window
 *
 */
int main()
{
    int a[] = {0, 1, 0, 1, 0, 1, 0};
    auto const& n = sizeof(a)/ sizeof(a[0]);

    unordered_map<int, int> psum;
    int left(0), right(0);

    int sum(0);
    for (int i = 0; i < n; i++) {
        sum += (a[i] == 0 ? -1 : 1);
        if (sum == 0) {
            left = 0;
            right = i;
            continue;
        }

        int ll = psum[sum];
        if (ll != -1) {
            ll++;
            if ((i - ll) > (right - left)) {
                left   = ll;
                right  = i;
            }
        } else {
            psum[sum] = i;
        }
    }

    cout << left << " " << right;
}
