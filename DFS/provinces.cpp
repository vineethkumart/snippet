//https://leetcode.com/problems/number-of-provinces/
class Solution {
    public:

        void dfs(int i, vector<vector<int>>& g, vector<int> & visited)
        {
            int n = g[i].size();
            assert(!visited[i]);
            visited[i] = true;

            for (int j = 0; j < n; j++) {
                if (g[i][j] && !visited[j]) {
                    dfs(j, g, visited);
                }
            }
        }

        int findCircleNum(vector<vector<int>>& g) {
            int n = g.size();
            vector<int> visited(n, 0);

            int provinces(0);
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    dfs(i, g, visited);
                    provinces++;
                }
            }

            return provinces;
        }
};

