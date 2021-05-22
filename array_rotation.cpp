#include <iostream>
#include <cassert>

using namespace std;

void reverse(int* a, int start, int end)
{
    while (start <= end) {
        std::swap(a[start++], a[end--]);
    }
}

void rotate_1(int *a, int n, int k)
{
    reverse(a, n-k, n-1);
    reverse(a, 0, n-k-1);
    reverse(a, 0, n-1);
}

void rotate_2(int *a, int n, int k)
{
    for (int i = 0; i < k; i++) {
        int temp = a[0];
        for (int j = 0; j < n-1; j++) {
            std::swap(a[j+1], a[j]);
        }
        a[n-1] = temp;
    }
}

/* Find pivot - Find the minimum element of sorted rotated array
binary search, search condition for returning is:
a[mid] < a[mid-1]
Else:
    a[mid] < a[high] ->  Left portion
    a[mid] > a[high] ->  Right portion
*/

int find_min(int* a, int low, int high)
{
    assert(low <= high);     // in BS this happens when element not found, cant happen here
    
    if (a[low] < a[high]) return low; // array not rotated
    if (low == high) return low;  // single element array
    
    int mid = (low + high)/2;
    
    if (mid > low && a[mid] < a[mid-1]) return mid;
    
    // recurse in one of the halves
    if (a[mid] < a[high]) return find_min(a, low, mid-1);
    
    find_min(a, mid+1, high);
}

int binsearch(int *a, int low, int high, int el)
{
    if (low > high) return -1;
    if (low == high && a[low] != el) return -1;
    
    int mid = (low + high)/2;
    if (a[mid] == el) return mid;
    
    if (a[mid] < el) return binsearch(a, mid+1, high,el);
    return binsearch(a, low, mid-1,el);
}

int search(int *a, int n, int el)
{
    int pivot = find_min(a, 0, n-1);
    if (a[pivot] == el) return pivot;
    
    if (a[n-1] < el) return binsearch(a, 0, pivot-1, el);
    binsearch(a, pivot+1, n-1, el);
}



int main()
{
    int a[] = {1,2,3,4,5,6,7};
    rotate_1(a, 7, 4);
    //rotate_2(a, 7, 1);
    for (int i = 0; i < 7; i++) std::cout << a[i] << " ";
    // searching sorted rotated array using binary search
    int pivot = find_min(a, 0, 6);
    std::cout << "\npivot(small element) is " << a[pivot];
    
    // Search for an element
    std::cout << endl << search(a, 7, 3);
    std::cout << endl << search(a, 7, 9);
    
    return 0;
}
