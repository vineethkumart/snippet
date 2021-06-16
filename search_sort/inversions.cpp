#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

int inversions(int a[], int l, int r)
{
    if (l >= r) return 0;

    int z(0);
    int mid = l + (r-l)/2;

    z += inversions(a, l, mid);
    z += inversions(a, mid+1, r);

    int n1 = mid-l+1;
    int n2 = r-mid;

    int x[n1];
    int y[n2];

    for (int i = 0; i < n1; i++) x[i] = a[l+i];
    for (int i = 0; i < n2; i++) y[i] = a[mid+1+i];

    // merge arrays
    int k = l;
    int i = 0; int j = 0;

    while (i < n1 && j < n2) {
        if (x[i] < y[j]) a[k++] = x[i++];
        else {
            a[k++]  = y[j++];
            z += n1-i;
        }
    }

    while (i < n1) a[k++] = x[i++];
    while (j < n2) a[k++] = y[j++];

    assert(i == n1);
    assert(j == n2);
    assert(k == r+1);

    return z;
}

int main() {
    int a[] = {5,4,3,1,2};
    int s = sizeof(a)/ sizeof(a[0]);
    int n = inversions(a, 0, s-1);
    cout << "inversions: " << n; 
    return 0;
}

