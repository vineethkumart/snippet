#include <iostream>
#include <string>
#include <climits>

using namespace std;

int window(string s, string t)
{
    int c[256] = {0};
    int count(0);
    for (int i = 0; i < t.size(); i++) {
        if (!c[t[i]]) count++;
        c[t[i]]++;
    }

    int j = 0;
    int i = 0;
    int start = 0;
    int len = INT_MAX;

    while (j < s.size()) {
        c[s[j]]--;
        if (c[s[j]] == 0) count--; // a char is found

        while (count == 0) { // try to shrink, after getting a window
            if (j - i + 1 < len) {
                len = j - i + 1;
                start = i;
            }

            // slide the window
            c[s[i]]++; // remove a character
            if (c[s[i]] > 0) count++; // got a char of interest, need to grow window to get a match
            i++; // grow window
        }

        j++; // grow window
    }

    cout << s.substr(start, len) << endl;;
    return len;
}

int main()
{
    string s = "adobecodebanc";
    string t = "abc";

    cout << window(s, t);

    return 0;

}
