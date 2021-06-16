#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0  
#define N 9  

/* Complexity:
 * 9^n2
 * */

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool isvalid(int g[N][N], int i, int j, int num)
    {
        bool valid(true);
        if (g[i][j] != 0) return false;
        
        // check if the number can be placed in the grid
        int r = i/3 * 3;
        int c = j/3 * 3;
        
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                if (g[r+p][c+q] == num) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (!valid) return valid;
        
        // check the entire row
        for (int p = 0; p < N; p++) {
            if (g[i][p] == num) {
                valid = false;
                break;
            }
        }
        
        if (!valid) return valid;
        
        // check the entire column
        for (int p = 0; p < N; p++) {
            if (g[p][j] == num) {
                valid = false;
                break;
            }
        }
        
        if (!valid) return valid;
        
        return true;
    }
    
    bool solved(int g[N][N])
    {
        bool solved(true);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][j] == 0) 
                {
                    solved = false;
                    break;
                }
            }
        }
        
        return solved;
    }
    
    bool dfs(int g[N][N], int i, int j, int num) {
        //cout << i << " " << j << ":" << num << endl;
        // place the number
        assert(isvalid(g, i, j, num));
        g[i][j] = num;
        if (solved(g)) return true;
        
        int ni = -1;
        int nj = -1;

        // find the next cell to place
        for (int p = 0; p < N; p++) {
            for (int q = 0; q < N; q++) {
                if (g[p][q] == 0) {
                    ni = p;
                    nj = q;
                    break;
                }
            }
            if (ni != -1) break;
        }

        assert(ni != -1 && nj != -1);

        // try placing a number
        for (int num = 1; num <= 9; num++) {
            if (isvalid(g, ni, nj, num)) {
                if (dfs(g, ni, nj, num)) return true;
            }
        }

        // backtrack
       // cout << "backtracking...\n";
        g[i][j] = 0;

        return false;
    }
    
    bool SolveSudoku(int g[N][N])  
    {
        // keep placing number and check for solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][j] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isvalid(g, i, j, num)) {
                            if (dfs(g,i,j,num)) return true;
                        }
                    }
                    return false;
                }
            }
        }
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int grid[N][N] = 
{{3,0,6,5,0,8,4,0,0},
{5,2,0,0,0,0,0,0,0},
{0,8,7,0,0,0,0,3,1},
{0,0,3,0,1,0,0,8,0},
{9,0,0,8,6,3,0,0,5},
{0,5,0,0,9,0,6,0,0},
{1,3,0,0,0,0,2,5,0},
{0,0,0,0,0,0,0,7,4},
{0,0,5,2,0,6,3,0,0}};
       
    Solution ob;
    if (ob.SolveSudoku(grid) == true)  
        ob.printGrid(grid);  
    else
        cout << "No solution exists";  

    cout<<endl;
    return 0;
}  // } Driver Code Ends
