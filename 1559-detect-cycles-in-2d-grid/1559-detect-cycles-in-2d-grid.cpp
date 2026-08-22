class Solution {
public:

    bool dfs(int r, int c, int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= grid.size() ||
                nc < 0 || nc >= grid[0].size())
                continue;

            if (grid[nr][nc] != grid[r][c])
                continue;

            if (!visited[nr][nc]) {
                if (dfs(nr, nc, r, c, grid, visited))
                    return true;
            }
            else if (nr != pr || nc != pc) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited))
                        return true;
                }
            }
        }

        return false;
    }
};