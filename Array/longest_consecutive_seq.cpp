// This shows how to systematically approach and get optimal solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int longest_bf(int a[], int n)
{
    // think from the bruteforce approach. How we can atleast solve this!
    // Take each element and look for the consecutive elements and keep a count, compare with global max and return the max found
    int gm(0);

    for (int i = 0; i < n; i++) {
        int num = a[i];
        int lm(1);
        // seach for consecutive elements
        for (int next = num+1; ; next++) {
            bool found(false);
            for (int e = 0; e < n; e++) {
                if (a[e] == next)  {found = true; break; }
            }

            if (found){
                lm++;
                gm = max(gm, lm);
            } else {
                break;
            }
        }
    }

    return gm;

    // This taken O(n3) time, think of  BUD
    // 1. Looking up for presence can be done in const time using a hash table - reduces to O(N2)
    // 2. Intuition - If we sort the array, next elements will be present in contig location and linear pass is sufficient once sorted.  O(nlogn)
    // 3. back to 1. Yes we need to use a hashtable but can we somehow process element only once? if so the outer loop is not required and will reduce to N
    //  Yes, Process the sequence starting from the minimum element only say 3,2,5,4 present and when you iterate, check if num-1 present if so skip, that will be processed with num-1
    //  So this sequence will be processed with 2 only.
    //
/*
 * Whats the complexity?
 * for each sequence beginning with a smallest number, the inner iteration is seq long
 * Hence each element is visited twice and not more.
 * Linear
 */
}

int longest_op(int a[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);

    int gm(0);
    for (auto i : s) {
        if (s.find(i-1) != s.end()) continue;
        int lm(1);
        int num = i+1;
        while (s.find(num) != s.end()) { num++; lm++; }
        gm = max(gm, lm);
    }

    return gm;
}

int main()
{
    //int a[] = {100,4,200,1,3,2};
    int a[] = {0,3,7,2,5,8,4,6,0,1};
    //cout << longest_bf(a, sizeof(a)/sizeof(a[0]));

    cout << longest_op(a, sizeof(a)/sizeof(a[0]));

    return 0;
}
