class Solution {
public:
    #define ll long long
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> prev(cols, 0), curr(cols, 0);
        prev[0] = grid[0][0];
        for(int i = 1 ; i < cols ; i++) {
            prev[i] = prev[i - 1] + grid[0][i];
        }

        for(int i = 1 ; i < rows ; i++) {
            curr[0] = prev[0] + grid[i][0];
            for(int j = 1 ; j < cols ; j++) {
                curr[j] = grid[i][j] + min(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[cols - 1];
        
    }
};