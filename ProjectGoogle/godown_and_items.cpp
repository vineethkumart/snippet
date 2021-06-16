/*
 ||***|**|******||**|*|||

 GIven start and end point, return number of items in a container.
 */

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;


int count(string s, int l, int r)
{
    // maintain a valid and invalid sum

    int n = s.size();
    int i = 0;
    while (s[i] != '|') i++; // skip initial out of the window items

    int valid[n];
    int invalid[n];

    memset(valid, 0, sizeof(valid));
    memset(invalid, 0, sizeof(invalid));

    int last(i);
    int count(0);
    int total(0);
    i++;
    for (; i < n; i++) {
        if (s[i] == '|') {
            // found a window,  fill items
            total += count;
            count = 0;
            for (int j = last+1; j <= i; j++) {
                invalid[j] = total;
            }
            last = i;
        } else {
            count++; // count an item
        }

        valid[i] = total;
    }


    return valid[r-1] - invalid[l-1];
}

int main()
{
    string s = "||***|**|******||**|*|||";

    assert (count(s, 1, 1) == 0);
    assert (count(s, 1, 5) == 0);
    assert (count(s, 1, 6) == 3);
    assert (count(s, 1, 7) == 3);
    assert (count(s, 2, 7) == 3);
    assert (count(s, 6, 13) == 2);
    assert (count(s, 6, 17) == 8);
    assert (count(s, 4, 17) == 8);

    return 0;
}
