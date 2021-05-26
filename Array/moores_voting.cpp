int majority(int *a, int size)
{
    int m = a[0]; count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == m) count++;
        else {
            count --;
            if (count == 0) {
                m = a[i]; count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == el) count++;
    }

    if (count > size/2) return el;
    return -1;
}
