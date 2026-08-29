class Solution {
public:

    int m, n;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    vector<vector<int>> dp;

    int dfs(int row, int col, vector<vector<int>>& matrix) {

        // Already calculated
        if(dp[row][col] != -1)
            return dp[row][col];

        int maxi = 1;

        // Check all 4 directions
        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // Valid cell + strictly increasing
            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               matrix[nrow][ncol] > matrix[row][col]) {

                maxi = max(maxi, 1 + dfs(nrow, ncol, matrix));
            }
        }

        return dp[row][col] = maxi;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        // Start DFS from every cell
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {

                ans = max(ans, dfs(row, col, matrix));
            }
        }

        return ans;
    }
};