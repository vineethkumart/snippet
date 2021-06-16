/* Given words and a string. Split the string into group of words. Return if possible else return false
 * 
 * Also can be enhanced to return number of such splits possible */


class Solution {
    public:
        bool wb(string s, unordered_set<string>& d, unordered_map<string, bool>& m)
        {
            if (s.empty()) return true;
            if (d.find(s) != d.end()) return true;
            if (m.find(s) != m.end()) return m[s];

            m[s] = false;
            bool& a = m[s];

            for (int i = 1; i < s.size(); i++) {
                if ((d.find(s.substr(0,i)) != d.end()) && wb(s.substr(i), d, m)) return (a = true);
            }
            return (a = false);
        }

        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> d;
            unordered_map<string, bool> mem;
            for (auto i : wordDict) d.insert(i);


            return wb(s, d, mem);
        }
};
