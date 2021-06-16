// This finds the majoiry element in a given array
// i.e any element occuring more than n/2 times
// idea is that me will contrinute n/2 times to the count and collective contribution of all remainign elements wil be < n/2 and hence
// e will be the majority element if at all exists
//
//

int majority(int *a, int size)
{
    int m = a[0];
    count = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == m) count++; else count--;
        if (count == 0) {
            m = a[i];
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == m) count++;
    }

    if (count > size/2) return m;

    return -1;
}
