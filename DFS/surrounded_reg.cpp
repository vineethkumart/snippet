/* Surrounded Regions:
 * https://leetcode.com/problems/surrounded-regions/
 * */

class Solution {
    public:
	void flip(vector<vector<char>>& board, int i, int j)
	{
	    int m = board.size();
	    int n = board[0].size();

	    auto isSafe = [&](int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	    };

	    assert(board[i][j] == 'O');
	    board[i][j] = '1'; // can't be flipped

	    int dx[] = {1,-1, 0, 0};
	    int dy[] = {0, 0, 1, -1};

	    for (int k = 0; k < 4; k++) {
		auto nx = i + dx[k];
		auto ny = j + dy[k];
		if (isSafe(nx, ny) && board[nx][ny] == 'O') {
		    flip(board, nx, ny);
		}
	    }
	}
	void solve(vector<vector<char>>& board) {
	    int m = board.size();
	    int n = board[0].size();

	    for (int i = 0; i < m; i++) if (board[i][0] == 'O') flip(board, i, 0);
	    for (int i = 0; i < m; i++) if (board[i][n-1] == 'O') flip(board, i, n-1);
	    for (int i = 0; i < n; i++) if (board[0][i] == 'O') flip(board, 0, i);
	    for (int i = 0; i < n; i++) if (board[m-1][i] == 'O') flip(board, m-1, i);

	    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		    if (board[i][j] == '1') board[i][j] = 'O';
		    else if (board[i][j] == 'O') board[i][j] = 'X';
		}
	    }
	}
};
