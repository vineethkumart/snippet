#include <iostream>

using namespace std;


void qksort(int a[], int l, int r)
{
    if (l >= r) return;

    int pivot = a[r]; // pivot
    int p(l);

    for (int i = l; i < r; i++) {
        if (a[i] < pivot) swap(a[p++], a[i]);
    }

    swap(a[p], a[r]);

    qksort(a, l, p-1);
    qksort(a, p+1, r);
}

void qksort_d(int a[], int left, int right)
{
    if (left >= right) return;

    int pivot = a[left];

    int l(left);
    int r(right);
    int m(left);

    while (m <= r) {
        if (a[m] < pivot) swap(a[m++], a[l++]);
        else if (a[m] > pivot) swap(a[m], a[r--]);
        else m++;
    }

    qksort_d(a, left, l-1);
    qksort_d(a, m, right);
}

int main()
{
    int a[] = { 8, 1, 3, 3, 4, 9, 11 ,4,  0, 9, 8 };
    int n = sizeof(a)/ sizeof(*a);
    qksort_d(a, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
}

