#include <iostream>
using namespace std;

int bsearch(int a[], int n, int l, int r, int el)
{
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (a[mid] == el) return true; // found
        if (el < a[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return false;
}


// abstract binary search
// seach on domain for a given value satisfying a predicate
// there will be an 'n' stuch that pred(n) will be false till n-1 and true from n onwards
// eg square root of a number
int absearch(int n, int l, int r)
{
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (mid * mid < n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int main()
{
    int a[] = {1,2,4,6,9,10,12,13,15};
    /*
    cout << bsearch(a, 9, 0, 8, 12) << endl;
    cout << bsearch(a, 9, 0, 8, 15) << endl;
    cout << bsearch(a, 9, 0, 8, 1) << endl;
    cout << bsearch(a, 9, 0, 8, 0) << endl;
    */

    int n = 49;
    cout << absearch(n, 0, (n/2)) << endl;
    return 0;
}
