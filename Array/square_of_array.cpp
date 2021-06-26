// Given array of +ve and -ve numbers sorted,
// return square of array

/* squaring and sorting is trivial, can we do better?
 * Yes, do a merge process and return
 * or use 2 pointer and return the max
 */

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> res(nums.size());
            int n = nums.size();
            int i = n-1;
            int l = 0;
            int r = i;

            while (i >= 0) {
                auto x = abs(nums[l]);
                auto y = abs(nums[r]);
                int s(0);
                if (x > y) {
                    s = x;
                    l++;
                } else {
                    s = y;
                    r--;
                }
                res[i] = s * s;
                i--;
            }

            return res;

        }
};
