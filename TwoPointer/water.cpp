/*
https://leetcode.com/problems/container-with-most-water
 *
 *  Given walls of different heights and whats the max water than can be tapped.
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        Naive solution is to consider all paris and get the area and return max area
        Takes O(N^2) time
        
        Think: 
            Do we really have to compare an element with all possible other elements, 
            A min element can contribute min*(max_difference) only.
            So if we get first and last element and get the area for the min element that the max it can 
            contribute, can discard that element after consideration
        */
        
        int m(0);
        int l(0), r(height.size() - 1);
        /*auto area = [&](int i, int j) -> int {
            return (min(height[i], height[j]) * abs(i-j));
        };*/
        int md(r);
        while (l < r) {
            int a = min(height[l], height[r]) * md;
            m = max(m, a);
            if (height[l] < height[r]) l++;
            else r--;
            md--;
        }
        
        return m;
    }
};
