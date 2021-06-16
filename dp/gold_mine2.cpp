/* This is a problem that can't be solved using memorization.
//
// Here miner can move 4 directionally and hence it can take multiple paths and answer from a state depends on from what state you came from
// Need to use Enumeration here and nothing else can be done
*/

class Solution {
    public:
	int collect(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited)
	{
	    int m = grid.size();
	    int n = grid[0].size();

	    auto isSafe = [&](int i, int j) { 
		return (i >= 0 && i < m && j >= 0 && j < n
			&& grid[i][j]);
	    };

	    assert(isSafe(i, j));

	    if (visited[i][j]) return 0;
	    visited[i][j] = true;

	    // collect gold
	    int result(0);

	    int dx[4] = {0, 0,  1, -1};
	    int dy[4] = {1, -1, 0,  0};
	    for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (isSafe(ni, nj)) {
		    result = max(result, collect(ni, nj, grid, visited));        
		}
	    }

	    result += grid[i][j];
	    visited[i][j] = false; // backtrack
	    return result;
	}


	int getMaximumGold(vector<vector<int>>& grid) {
	    int m = grid.size();
	    int n = grid[0].size();

	    vector<vector<int>> visited(m, vector<int>(n,0));

	    int maxgold(0);
	    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		    if (grid[i][j]) {
			assert(!visited[i][j]);
			maxgold = max(maxgold, collect(i, j, grid, visited));
		    }
		}
	    }

	    return maxgold;
	}
};
