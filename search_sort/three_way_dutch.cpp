/* can be used for 3 way partitioning */ 

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {0,1,-1,-1,0,0,0,1,1,-1,-1,0};
    const auto& n = sizeof(a)/sizeof(a[0]);

    int l(0);
    int r(n-1);
    int i(0);

    while (i <= r) {
        switch(a[i]) {
            case -1:
                swap(a[l++], a[i++]);
                break;
            case  0:
                i++;
                break;
            case  1:
                swap(a[r--], a[i]);
                break;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
