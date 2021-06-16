/*
 * Find smallest window containing all characters of the given string
 *
 *
 * Can use Sliding window techniques. what we have seen so far.
 *
 * Grow the window to get a window containing all characters, and now shrink as long as its valid and record the minimum
 *
 */


// This is same as the max window with k distinct character type, grow the window  and later shrink

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int min_window(string s)
{
    int cw(0);
    int start(0);
    int unique(0);

    int f[256];
    int m(10000);
    memset(f, 0, sizeof(f));

    for (int i = 0; i < s.size(); i++) {
        f[s[i]]++;
        if (f[s[i]] == 1) unique++;
    }

    memset(f, 0, sizeof(f));

    for (int i = 0; i < s.size(); i++) {
        f[s[i]]++;
        if (f[s[i]] == 1) cw++;

        // shrink as long as valid window
        while (cw == unique) {
            m = min(m, i - start + 1);
            f[s[start]]--;
            if (f[s[start]] == 0) cw--; // lost a character
            start++;
        }
    }

    return m;
}

int main()
{
    string str("aa bbcda dd");
    cout << min_window(str); // prints 5
    return 0;
}
