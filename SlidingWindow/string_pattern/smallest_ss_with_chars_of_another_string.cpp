/*
 * Given 2 strings s and t. find smallest window in s containing another string t
 * N3 is trivial
 * Grow the window and stop once you get a window with all of t into to
 * Try to shrink by keeping the invariant. record the minimum
 *
 */
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int min_window(string s, string t)
{
    int m(10000);
    int start(0);

    int f[256];
    memset(f, 0, sizeof(f));
    int window(0);
    int cw(0);

    for (int i = 0; i < t.size(); i++) {
        f[t[i]]++;
        if (f[t[i]] == 1) window++;
    }

    for (int i = 0; i < s.size(); i++) {
        f[s[i]]--;
        if (f[s[i]] == 0) cw++; // got a character from t thats preset in s

        // try to shrink keeping the invariant
        while (cw == window) {
            m = min(m, i - start + 1);
            f[s[start]]++;
            if (f[s[start]] == 1) cw--; // lost a character
            start++;
        }

    }

    return m;
}

int main()
{
    //cout << min_window("this is a test string", "tist");
    cout << min_window("timetopractice", "toc");
    return 0;
}
