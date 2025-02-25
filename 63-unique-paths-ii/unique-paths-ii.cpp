class Solution {
public:
    int find(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        cout << row << " " << col << endl;
        if(row == 0 && col == 0) {
            if(grid[row][col] == 1) return 0;
            return 1;
        }
        if(row < 0 || col < 0 || grid[row][col] == 1) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int top = 0, left = 0;
        top = find(row - 1, col, grid, dp);
        left = find(row, col - 1, grid, dp);
        return dp[row][col] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        return find(rows - 1, cols - 1, obstacleGrid, dp);

    }
};