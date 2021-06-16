#include <iostream>
#include <vector>

using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> p(n, 1);

    long long t = nums[0];
    for (int i = 1; i < n; i++) {
        p[i] = t;
        t *= nums[i];
    }

    t = nums[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        p[i] *= t;
        t *= nums[i];
    }

    return p;
}
int main()
{
    vector<long long int> nums{10, 3, 5, 6, 2};
    vector<long long int> p = productExceptSelf(nums, nums.size());

    for (auto i : p) cout << i << " ";
    return 0;
}
