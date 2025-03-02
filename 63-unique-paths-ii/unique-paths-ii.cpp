class Solution {
public:
    // int find(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    //     if(row < 0 || col < 0 || grid[row][col] == 1) return 0;
    //     if(row == 0 && col == 0) return 1;
    //     if(dp[row][col] != -1) return dp[row][col];
    //     int top = 0, left = 0;
    //     top = find(row - 1, col, grid, dp);
    //     left = find(row, col - 1, grid, dp);
    //     return dp[row][col] = top + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        
        int i = 0;
        while(i < cols && obstacleGrid[0][i] != 1) {
            dp[0][i] = 1;
            i++;
        }

        bool flag = false;
        if(obstacleGrid[0][0] == 1) flag = true;
        for(int i = 1 ; i < rows ; i++) {
            if(obstacleGrid[i][0] == 1) flag = true;
            if(flag == false) dp[i][0] = 1;
            for(int j = 1 ; j < cols ; j++) {
                int x = 0;
                if(dp[i][j - 1] != -1) x += dp[i][j - 1];
                if(dp[i - 1][j] != -1) x += dp[i - 1][j];
                if(obstacleGrid[i][j] != 1) dp[i][j] = x;
            }
        }
        return dp[rows - 1][cols - 1] == -1 ? 0 : dp[rows - 1][cols - 1];



    }
};