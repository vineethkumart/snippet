
// 2 way partitioning
int main()
{
    int a[] = {0,1,1,0,0,1,1,0,0,1,1,0,0,1};
    
    int l = 0;
    int r = 12;
    
    
    while (l <  r) {
        while (a[l] == 0) l++;
        while (a[r] == 1) r--;
        
        std::swap(a[l], a[r]);
        l++; r--;
    }
    
    for (int i = 0; i <= 12; i++) std::cout << a[i] << " ";
}

//3 way partitioning
int main()
{
    int a[] = {0,1,1,2,0,2,1,0,0,2,1,0,2,1};
    
    int l = 0;
    int r = sizeof(a)/sizeof(a[0]) - 1;
    int mid = 0;
    
    while (mid <= r) {
        switch (a[mid]) {
            case 0:
                std::swap(a[l++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(a[r--], a[mid]);
                break;
            default:
                break;
        }
    }
    
    for (int i = 0; i <= 12; i++) std::cout << a[i] << " ";
}