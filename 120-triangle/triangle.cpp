class Solution {
public: 
    #define ll long long
    int find(int row, int i, vector<vector<int>> &t, vector<vector<int>> &dp) {
        if(row >= t.size()) return 0;
        if(i < 0 || i >= t[row].size()) return INT_MAX;
        if(dp[row][i] != -1) return dp[row][i];
        ll left = t[row][i] + find(row + 1, i, t, dp);
        ll right = t[row][i] + find(row + 1, i + 1, t, dp);
        return dp[row][i] = min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[rows - 1].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        return find(0, 0, triangle, dp);
    }
};