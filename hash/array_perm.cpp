#include <iostream>
#include <unordered_map>

using namespace std;
/*
 * Given an array and a number n, change array to have elements in range 1-n with minimum replacement
 * Input : A[] = {2, 2, 3, 3}
    Output : 2 1 3 4
 */


int main()
{
    int a[] = {2,2,3,6,7,10,4,4};
    int n = 8;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) count[a[i]]++;

    int next_el = 1;
    for (int i = 0; i < n; i++) {
        // look for a next el 
        while (count.find(next_el) != count.end()) next_el++;

        if (a[i] > n || count[a[i]] != 1) {
            // replace with next el
            count[a[i]]--;
            a[i] = next_el;
            count[next_el] = 1;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << ", ";

    return 0;
}

