class Solution {
public:
    int find(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i >= s.size() || j >= t.size()) {
            if(j == t.size()) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0, notTake = 0;
        if(s[i] == t[j]) {
            take = find(i + 1, j + 1, s, t, dp);
        }
        notTake = find(i + 1, j, s, t, dp);
        return dp[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return find(0, 0, s, t, dp);
    }
};