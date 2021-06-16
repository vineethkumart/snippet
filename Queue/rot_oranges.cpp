class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
    
        int m = grid.size();
        int n = grid[0].size();
    
        auto isdone = [&]() {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        return false;
                    }
                }
            }
            
            return true;
        };
        
        if (isdone()) return 0;
        
        int pass = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto e = q.front();q.pop();
                // rot oranges on proximity
                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};
                
                for (int d = 0; d < 4; d++) {
                    int ni = e.first + dx[d];
                    int nj = e.second + dy[d];
                    if (ni < 0 || ni >= m) continue;
                    if (nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] != 1) continue;
                    grid[ni][nj] = 2; // rot
                    q.push(make_pair(ni, nj)); // new state change
                }
            }
            if (isdone()) return pass; // done
            if (q.empty()) return -1; // not possible at all
            pass++;
        }
        
        return -1;
    }
};
