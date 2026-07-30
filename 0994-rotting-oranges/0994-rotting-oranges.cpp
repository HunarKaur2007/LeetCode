class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Find all rotten oranges and count fresh ones
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2)
                    q.push({i, j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // No fresh oranges
        if(fresh == 0)
            return 0;

        int minutes = 0;

        // 4 directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int size = q.size();
            bool rottenThisMinute = false;

            // Process one level (one minute)
            while(size--) {

                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                // Check all 4 neighbours
                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Valid fresh orange
                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;      // Rot it
                        fresh--;               // One less fresh orange
                        q.push({nr, nc});      // It will spread next minute
                        rottenThisMinute = true;
                    }
                }
            }

            if(rottenThisMinute)
                minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};