class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        // take q to store rotten fruits,
        // do multisources bfs

        // declare queue<time,<row,col>>
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // declare a visited where
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // store rotten fruits coordinate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }
        int maxi = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int time = q.front().first;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                    visited[nrow][ncol] == 0) {
                        visited[nrow][ncol] = 1;
                    maxi = max(maxi, time + 1);
                    q.push({time + 1, {nrow, ncol}});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    return -1;
                    break;
                }
            }
        }
        return maxi;
    }
};
