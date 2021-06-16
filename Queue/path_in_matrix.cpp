/*
    State minimization/maximization problems can bs solved either using DFS+Memorization(DP) or BFS



Minimum steps required to reach the end of a matrix
Given a matrix containing 0,1 and 2. 0 means you can walk through the cell, 1 you can't. 2 is the cell where you are standing
You need to find minimum length path to any of the boundaries

You can move:
1. 4-directionally - Left, Right, Top, Bottom
2. 8-directionally - 4-directions + 4-diagonal directions
*/

/*
DP

For Recursive problems using DP:
1. You can either use separate visited and mem arrays of can be done with one mem array
2. You should keep a visited value in the mem array before processing the cell so that recursive calls to same cell are prevented


*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

const int m = 4;
const int n = 5;

using namespace std;

int paths(int mat[m][n], int i, int j, int mem[m][n])
{
    if (i == 0 || j == 0 || i == m-1 || j == n-1) return 0;

    auto isSafe = [&](int i, int j) { return i >=0 && i < m && j >= 0 && j < n;};

    if (mem[i][j]) return mem[i][j];

    mem[i][j] = INT_MAX; // visit

    // compute
    int result = INT_MAX; // INT_MIN if its maximization problem

    int x[4] = {0,  0,  1, -1};
    int y[4] = {1, -1,  0,  0};

    for (int k = 0; k < 4; k++) {
        const int ni = i + x[k];
        const int nj = j + y[k];
        if (!isSafe(ni, nj)) continue;              // not safe
        if (mat[nj][nj] != 0) continue;             // can't visit
        result = min(result, paths(mat, ni, nj, mem));
    }

    if (result == INT_MAX) return result;
    mem[i][j] = result + 1;
    return mem[i][j];
}


int main()
{
    int mat[m][n] =  {{1, 1, 1, 0, 1},
                        {1, 0, 2, 0, 1},
                        {0, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0}};


    int mem[m][n];
    memset(mem, 0, sizeof(mem));
    int res = paths(mat, 1,2,mem);
    if (res == INT_MAX) res = -1;

    cout << res;
    return 0;
}

