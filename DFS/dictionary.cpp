/*
 * Given a dictionary and a matrix of characters.
 * You can mode 8-directionally
 * Find words that are present in dictionary
 * */

/* Straight forward DFS will do */

/* Optimization: Use a Trie to make informed decision on traversal
 *
 * Trie - Insert the dictionay into trie
 * At any character c, traverse to anoter c' only if c' is child of c in the trie. */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
        void wb(int i, int j,
                vector<vector<char> >& b, 
                unordered_set<string>& d, 
                string& s, unordered_set<string>& o, vector<vector<bool>>& v)
        {
            int m = b.size();
            int n = b[0].size();

            if (d.find(s) != d.end()) {
                o.insert(s);
            }

            assert(v[i][j] == false);

            v[i][j] = true; // visit

            int dx[] = {0, 0,  1, -1, 1, -1, -1, 1};
            int dy[] = {1, -1, 0,  0, -1, 1, -1, 1};

            for (int x = 0; x < 8; x++) {
                int ni = i + dx[x];
                int nj = j + dy[x];
                if (ni < 0 || ni >= m) continue;
                if (nj < 0 || nj >= n) continue;
                if (v[ni][nj]) continue;

                // else got a thing, visit
                s.push_back(b[ni][nj]);
                wb(ni, nj, b, d, s, o, v);
                s.pop_back(); // backtrack
            }

            v[i][j] = false; // backtrack
        }


        vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
            int m  = board.size();
            int n = board[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, 0));
            unordered_set<string> d;
            unordered_set<string> out;
            for (auto i : dictionary) d.insert(i);

            string w;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    w.push_back(board[i][j]);
                    wb(i, j, board, d, w, out, visited);
                    w.pop_back();
                }
            }
            vector<string> o;
            for (auto i : out) o.push_back(i);
            return o;
        }
};


/*
   C   A   P
   A   N   D
   T   I   E
   */


