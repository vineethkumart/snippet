/* Given a string and you need to partition that string into parts and each part should contain unique characters only
https://leetcode.com/problems/partition-labels
*/

// This can be done in linear time with constant space. Idea is to remember the last position and do linear scan
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int f[256];
            for (int i = 0; i < s.size(); i++) {
                f[s[i]] = i; // last found position of every character.
            }

            vector<int> ans;
            int p = 0;
            int start = 0;
            for (int i = 0; i < s.size(); i++) {
                p = max(p, f[s[i]]);
                if (i >= p) {
                    // got a partition
                    ans.push_back(p-start+1);
                    start = i+1;
                }
            }
            return ans;
        }
};

