/*
 * given a string and a number 
 
 * Think bruteforce as always, start with this and apply BUD. you will get it nothing to worry
 *
 * n3 is trivial
 * n2: check [i to j] for each i from 0 to n. remember unique chars in a map and every time when you grow check and grow
 * if violates record max and start from i+1
 *
 *
 * can we make it linear? yes
 * we don't have to again re-do(D) from i+1, we can shrink window to i' thus skipping un-necessary work
 * Remember the frequency in a map and shrink
 *
 * Linear in time
 */
 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int kUniques(string s, int k)
{
    int start = 0;
    int m = 0;
    int f[256];
    memset(f, 0, sizeof(f));

    auto Valid = [&]() -> bool {
        int u(0);
        for (int i = 0; i < 256; i++) {
            if (f[i]) u++;
        }

        return u <= k;
    };

    for (int i = 0; i < s.size(); i++) {
        f[s[i]]++; // grow window
        while (!Valid()) {
            f[s[start]]--;
            start++;
        }

        m = max(m, i-start+1);
    }

    return m;

}

int main()
{
    //string s = "aabacbebebe";
    string s = "abbcceefg";
    int k = 3;
    cout << kUniques(s, k);
    return 0;
}
