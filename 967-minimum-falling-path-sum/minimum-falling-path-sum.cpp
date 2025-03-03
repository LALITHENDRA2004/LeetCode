class Solution {
public:
    #define ll long long
    ll find(int row, int col, vector<vector<int>> &mat, vector<vector<ll>> &dp) {
        if(col >= mat[0].size() || col < 0) return INT_MAX;
        if(row == mat.size() - 1 && col >= 0 && col < mat[0].size()) return mat[row][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];
        ll left = mat[row][col] + find(row + 1, col - 1, mat, dp);
        ll down = mat[row][col] + find(row + 1, col, mat, dp);
        ll right = mat[row][col] + find(row + 1, col + 1, mat, dp);
        return dp[row][col] = min(down, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<ll>> dp(rows, vector<ll> (cols, INT_MAX));
        ll mini = INT_MAX;
        for(int i = 0 ; i < cols ; i++) {
            ll res = find(0, i, matrix, dp);
            mini = min(mini, res);
        }
        return mini;
    }
};