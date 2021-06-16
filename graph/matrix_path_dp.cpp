/* given a matrix and find the longest increasing path
 *
 * Here We can memorize. why? When we reach a cell from multiple paths, we can't take those path back as its increasing
 * hence there are only fixed paths from a cell. use memorization
 * */

#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
{
    int m = matrix.size();
    int n = matrix[0].size();

    assert(matrix[i][j] != INT_MIN); // not visited, to handle -ve numbers if any

    int cur = matrix[i][j];
    matrix[i][j] = INT_MIN; // visiting

    auto canmove = [&](int i, int j) -> bool {
        if (i < 0 || i >= m) return 0;
        if (j < 0 || j >= n) return 0;
        if (matrix[i][j] == INT_MIN) return 0;
        return 1;
    };

    int& ans = dp[i][j];
    if (ans) return ans;

    // can move to 4 directions from i,j
    int dx[4] = {1,-1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int mp(0);
    for (int x = 0; x < 4; x++) {
        int nx = i + dx[x];
        int ny = j + dy[x];
        if (canmove(nx, ny) && matrix[nx][ny] > cur) {
            int w = dfs(nx,ny,matrix);
            mp = max(mp, dfs(nx,ny,matrix));
        }
    }

    // done
    matrix[i][j] = cur;
    return (ans = mp + 1); // Note: always do like this, if you do inside loop boundary condition of returning 1 wont happen and will return 0
    // Also don't ever directly modify the result inside loop. compute to local variable and assign here
}



int main()
{
    //vector<vector<int>> a = {{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>> a = {{9,9,4},{6,6,8},{2,1,1}};

    int m = a.size();
    int n = a[0].size();

    int path = 0;
    dfs(0,1,a);

    /*
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            path = max(path, dfs(i, j, a));
        }
    }

    cout << path;
    */

    return 0;
}
