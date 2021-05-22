// Re-arrange array of elements in 0-n-1 to
// a[a[i]] = i;

int main()
{
    int a[] = {1, 3, 0, 2};

    int val = 0;
    int i = a[val];

    while (i != 0) { // do till i reaches back, like a circular linked list
        // remember next link in chain
        new_i = a[i];

        // modify
        a[i] = val;
        
        // update
        val = i;
        i = new_i;
    }
}
/*
Above will work only if its a single cycle circular linked list.
If there are more cycles, we have to keep a visited flag or something and repeate for all non-visited elements
Can keep the visited flag as follows as well:
    increment all elements by 1
    and Once visited, keep it -ve
    Once processed, negate and decrement 1
*/
/* Another Solution
Store 2 values in an index, old value and a new value
as:
    value += (old_val % MAX) * MAX;
    get value as % MAX and new_value as / MAX
*/
