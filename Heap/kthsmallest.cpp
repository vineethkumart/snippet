#include <iostream>
#include <queue>
using namespace std;


// quick select algorithm using partitioning of qs
int kthSmallest(int arr[], int l, int r, int k) {
    if (l >= r) return (l == k-1 ? arr[l] : -1);

    int n = r-l+1;
    int rp = (rand() % n);
    swap(arr[l+rp], arr[r]);
    int pivot = arr[r];
    int s(l);
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) {
            swap(arr[s++], arr[i]);
        }
    }
    swap(arr[s], arr[r]);

    if (s == k-1) return arr[s];
    if (s < k) {
        return kthSmallest(arr, s, r, k);
    }

    return kthSmallest(arr, l, s-1, k);
}

int main()
{
    int a[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    auto const n = sizeof(a)/ sizeof(*a);

    priority_queue<int, deque<int>, std::greater<int>> pq; // min heap
    for (int i =0; i < n; i++) {
        pq.push(a[i]);
    }

    int el;
    for (int i = 0; i < k; i++) {
        el = pq.top();
        pq.pop();
    }

    cout << el;
    return 0;
}
