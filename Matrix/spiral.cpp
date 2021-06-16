#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> res;
        const auto& rows = matrix.size();
        const auto& cols = matrix[0].size();
        int r = 0;
        int c = 0;
        
        while ( r <= (rows)/2 && c <= (cols)/2) {
            for (int j = c; j < cols-c; j++)  res.push_back(matrix[r][j]); // L2R
            for (int j = r+1; j < rows - r; j++)  res.push_back(matrix[j][cols-c-1]); // T2B
            for (int j = cols-c-2; j >= c; j--) res.push_back(matrix[rows-r-1][j]); // R2L
            for (int j = rows-r-2; j > r ; j--)  res.push_back(matrix[j][c]); // B2T
            r++; c++;
        }
    return res;
    }

};

int main()
{
    Solution s;
    auto i = s.spiralOrder({{1,2,3}, {4,5,6}, {7,8,9}});
    for (auto e : i) cout << e <<" ";
    return 0;
}
