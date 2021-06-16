/* matrix of 1s and 0s given, find the max connected component kind */

class Solution {
    public:

        void visit(vector<vector<char>>& grid, int i, int j)
        {
            assert(grid[i][j] == '1');

            int m = grid.size();
            int n = grid[0].size();
            auto safe = [&](int i, int j) -> bool {
                return i >= 0 && i < m && j >=0 && j < n;
            };

            grid[i][j] = '0'; // capture/ visit it
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (safe(x, y) && grid[x][y] == '1')  visit(grid, x, y); // capture it
            }
        }

        int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            int island(0);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1') {
                        visit(grid, i, j);
                        island++;
                    }
                }
            }

            return island;
        }
};
