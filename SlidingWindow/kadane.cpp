#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Given +ve and -ve numbers and find largest sum subarray:
 * BF -> [i...j] j varies from i+1 to n and i varies from 0 to n
 * so process each subarry n3 time if you are not storing sum else n2
 *
 * Observation: start finding sum from i and moment you get sum < element then you can discard the sum till that i and start from i+1 onwards
 * This is avoiding Duplicate work
 * */


int kadane(int a[], int n, int&left, int& right)
{
    int sum(0);
    int m(0);
    left = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] > sum) { // a[i] alone greater than sum, then discard sum received
            left = i;
            sum = a[i];
        }

        if (sum  > m) {
            right = i;
            m = sum;
        }

        //sum = max(sum + a[i], a[i]); // either sum+i or i
        //m = max(m, sum); // record max sum
    }

    return m;
}

int kadane_product(int a[], int n, int&left, int& right)
{
    int mx(1), mn(1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) swap(mx, mn);

        mx = max(mx, mx * a[i]);
        mn = min(mn, mn * a[i]);

        ans = max(ans, mx);
    }

    return ans;
}


/*
int kadane(int a[], int n, int&left, int& right)
{
    int sum(0);
    int cl(0);
    int cs(0);

    for (int i = 0; i < n; i++) {
        cs += a[i];
        if (cs > sum) {
            left = cl;
            right = i;
            sum = cs;
        } else if (cs < 0) {
            cs = 0;
            cl = i+1;
        } else {
            // nothing, just grow
        }
    }

    return sum;
}
*/

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    int left, right;
    int sum = kadane(a, 8, left, right);


    while (left <= right) cout << a[left++] <<" ";
    cout << "sum: " << sum;
    // 4 -1 -2 1 5 sum: 7
    return 0;
}
