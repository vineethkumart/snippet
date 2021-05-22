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


void merges(int *a, int left, int right)
{
    if (left >= right) return;
    int mid = (left+right)/2;
    merges(a, left, mid);
    merges(a, mid+1, right);
    
    // merge both subarrays
    int n1 = mid-left+1;
    int n2 = right-mid;
    int l[n1];
    int r[n2];
    
    for (int i = 0; i < n1; i++) l[i] = a[left+i];
    for (int i = 0; i < n2; i++) r[i] = a[mid+1+i];
    
    // merge l and r
    int k = left;
    int i = 0, j = 0; 
    while (i < n1 && j < n2)
        if (l[i] < r[j])
            a[k++] = l[i++];
        else 
            a[k++] = r[j++];
        
    while (i < n1)
        a[k++] = l[i++];
        
    while (i < n2)
        a[k++] = r[i++];
}


// This chooses last element as the pivot
void  quick_sort(int *a, int left, int right)
{
    if (left >= right) return;
    int pivot = a[right];
    int sorted = left;
    
    for (int i = left; i <= right-1; i++) {
        if (a[i] < pivot) {
            std::swap(a[i], a[sorted]);
            sorted++;
        }
    }
    std::swap(a[sorted], a[right]);
    qssort(a, left, sorted-1);
    qssort(a, sorted+1, right);
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


Quick select
------------
