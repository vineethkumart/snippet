#include <iostream>
#include <vector>

/*
 * You are given an array of weights and a scale, you should arrange weights in such a way that scale should alternate
 Let another weight array is [2, 3, 5, 6] 
and steps = 10 then, 3, 2, 3, 5, 6, 5, 3, 
2, 3 is the sequence in which weights should
be kept in order to move scale alternatively.
 */
using namespace std;

bool possible(int p, int q, int c, int* a, int n, int s, int steps, vector<int>& path)
{
    if (s == steps) return true;

    for (int i = 0; i < n; i++) {
        if (i != c)  {
            if (q + a[i] > p) {
                // a possible path
                q += a[i];
                path.push_back(i);
                if (possible(q, p, i, a, n, s+1, steps, path)) {
                    return true;
                }

                // backtrack
                q -= a[i];
                path.pop_back();
            }
        }
    }

    return false;
}

int main()
{
    int a[] = {2,3,5,6};
    int n = 4;
    int steps = 15;
    vector<int> path;

    for (int i = 0; i < 4; i++) {
        int p = a[i];
        int q = 0;
        int s = 1;
        if (possible(p, q, i, a, n, s, steps, path)) {
            for (auto e : path) cout << a[e] << ", ";
            break;
        }
    }
}

