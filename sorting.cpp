#include <iostream>
#include <cstdint>
using namespace std;

void bubble_sort(uint32_t *a, uint32_t N)
{
    for (uint32_t i = 1; i < N; i++) {
        for (uint32_t j = 0; j < N-i; j++) {
            if (a[j+1] < a [j]) std::swap(a[j], a[j+1]);
        }
    }
}

void insertion_sort(uint32_t *a, uint32_t N)
{
    // elements till i-1 are sorted, sort and keep the element a[i] in place
    for (uint32_t i = 1; i < N; i++) {
        for (int32_t j = i-1; j >= 0; j--) {
            if (a[j+1] < a[j]) std::swap(a[j+1], a[j]);
            else break;
        }
    }
}

void selection_sort(uint32_t*a, uint32_t N)
{
    // select the min element for the rest and move to begin
    for (uint32_t i = 0; i < N; i++) {
        uint32_t min = i;
        for(uint32_t j = i+1; j < N; j++) {
            if (a[j] < a[min]) min = j;
        }
        std::swap(a[i], a[min]);
    }
}


void merge(uint32_t*a, uint32_t l, uint32_t r)
{
    // make copies of the array
    uint32_t mid = (l+r)/2;
    uint32_t n1 = (mid-l)+1;
    uint32_t n2 = (r-mid);
    int L[n1];
    int R[n2];
    for (uint32_t i = 0; i < n1; i++) L[i] = a[i+l];
    for (uint32_t i = 0; i < n2; i++) R[i] = a[i+mid+1];

    uint32_t p = 0, q = 0;
    uint32_t i = l;
    while (p < n1 && q < n2) {
        if (L[p] < R[q])
            a[i++] = L[p++];
        else
            a[i++] = R[q++];
    }

    while (p < n1) a[i++] = L[p++];
    while (q < n2) a[i++] = R[q++];
}
void merge_sort(uint32_t*a, uint32_t l, uint32_t r)
{
    if (l >= r) return;
    uint32_t mid = (l+r)/2;

    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,r);
}


void quick_sort(uint32_t*a, uint32_t N)
{
    // Select a pivot 
}


void print(uint32_t* a, uint32_t N)
{
    for (uint32_t i = 0; i < N; i++) std::cout << a[i] << " ";
    std::cout << endl;
}


int main(int argc, char** argv)
{
    uint32_t a[] = {5,1,0,8,2,3,7,6};
    bubble_sort(a, sizeof(a)/sizeof(a[0]));
    print(a,sizeof(a)/sizeof(a[0]));

    return 0;
}