/*
 * Whats a segment tree
 * --------------------
 *
 *  Its an array that stores interval properties. Its a full binary tree. all nodes have 0 or 2 children. 
 *  leaves contain the data and internal nodes contain data for the interval
 *
 *  int arr[] = {1,2,3,4,5} and lets say we have to support queries in intervals. like min value in interval i,j. sum of values in i,j. number of 0s in i,j etc.,
 *  since its full NT this will have n leaves and n-1 internal nodes ==> 2n -1 nodes in total
 *  size of the array could be more if n is not power of 2. need 2n-1 where n is the next power of 2.
 *
 *  say for 10 nodes - 31 is array size --> still linear size.
 *
 *  Segmene Tree representation
 *  Root for interval [0-5] inclusive and left for [0-2] and right [3-5] i.e l-mid, mid+1-r
 *  when l == r store the leaf value
 */


#include <iostream>
#include <cmath>

using namespace std;

int phi(int a, int b) { return a+b; }

int stree(int st[], int a[], int s, int e, int i)
{
    if (s == e) {
        st[i] = a[s];
        return a[s];
    }

    int mid = s + (e-s)/2;

    int s1 = stree(st, a, s, mid, 2*i+1);
    int s2 = stree(st, a, mid+1, e, 2*i+2);

    st[i] = phi(s1, s2);
    return st[i];
}


int query(int st[], int s, int e, int i, int q1, int q2)
{
    // query will take log N time, go to all relevant intervals, gather the info and build it up

    // if current node is contained in query return it, no point in going left/right

    if (s >= q1 && e <= q2) return st[i];

    // if current node does not contribute, return 0
    if (e < q1 || s > q2) return 0;

    int mid = s + (e-s)/2;
    int s1 = query(st, s, mid, 2*i+1, q1, q2);
    int s2 = query(st, mid+1, e, 2*i+2, q1, q2);

    return phi(s1,s2);
}

int main()
{
    int a[]  = {1,2,3,4,5,6,7};
    int n = sizeof(a)/ sizeof(a[0]);

    // round off to next power of 2
    int m = 1 << (int) ceil(log2(n));

    int st[m*2];
    stree(st, a, 0, n-1, 0);

    cout  << query(st, 0, n-1, 0, 3, 5);
    return 0;
}
