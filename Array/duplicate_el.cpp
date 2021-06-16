// Give positive numbers in range 1..n and exactly one number is repeating
// Input: nums = [1,3,4,2,2]
// Output: 2
// Find dupliate number
//
// This can be found out with prev approach of in place modifying array
// but can find out w/o modifying array using 
//
// =====> Floyd Tortoise and Hair algo
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        // find entry point
        s = nums[0];
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }

        return s;
    }
};
