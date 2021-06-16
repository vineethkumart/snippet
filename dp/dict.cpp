class Solution {
public:

    bool find(string s, set<string>& d, map<string, bool>& mem)
    {
        if (s.empty()) return true;
        if (d.find(s) != d.end()) return true;
        
        if (mem.find(s) != mem.end()) return mem[s];
        
        int a(false);
        for (int l = 1; l < s.length(); l++) {
            if (d.find(s.substr(0, l)) != d.end() && find(s.substr(l), d, mem)) {
                a = true;
            }
        }
        mem[s] = a;
        return a;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> d;
        map<string, bool> mem;
        for (auto i : wordDict) d.insert(i);
        return find(s, d, mem);
    }
};

/* complexity
 *
 *
 *Normal T(n) = T(k) + T(n-k) for all possible k;

 O(n2n);

 Memorization
 n2

 *
 *
 *
 *
 * Can be done using BFS as well. using a queue<int> storing the index in the queue where things matched.
