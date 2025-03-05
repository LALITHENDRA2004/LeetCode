class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(rows, vector<int> (cols, INT_MAX));

        for(int i = 0 ; i < cols ; i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1 ; i < rows ; i++) {
            for(int j = 0 ; j < cols ; j++) {
                int mini = INT_MAX;

                int left = INT_MAX, right = INT_MAX;
                int top = matrix[i][j] + dp[i-1][j];
                if(j > 0) left = matrix[i][j] + dp[i-1][j-1];
                if(j < matrix.size()-1) right = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(top, min(left, right));

                if(i == rows-1) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans == INT_MAX ? matrix[0][0] : ans;
    }
};