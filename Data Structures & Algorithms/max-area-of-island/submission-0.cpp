class Solution {
   private:
    void dfs(vector<vector<int>>& grid, int row, int col, int delrow[], int delcol[],
            vector<vector<int>>& visited, int& area) {
        // mark current element is visited
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        // traversing
        for (int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            // now we check the adjacent element of grid is 1 or not similarly check it must be not
            // visited and i and j in grid
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                grid[newrow][newcol] == 1 && visited[newrow][newcol] == 0) {
                // visited[newrow][newcol]=1;
                area++;
                dfs(grid, newrow, newcol, delrow, delcol, visited, area);
            }
        }
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // declare visited grid initiallize d with -1
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // to count distinct island
        int count = 0;
        // for traversing the adjacent node
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int maxi = 0;

        // traverse in grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int area = 1;
                    dfs(grid, i, j, delrow, delcol, visited, area);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
