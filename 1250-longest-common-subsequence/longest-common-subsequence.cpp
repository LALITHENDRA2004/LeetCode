class Solution {
public:
    int find(int i1, int i2, string &t1, string &t2, vector<vector<int>> &dp) {
        if(i1 == 0 && i2 == 0) {
            if(t1[i1] == t2[i2]) return 1;
            return 0;
        }
        if(i1 == 0) {
            int x = find(i1, i2 - 1, t1, t2, dp);
            if(t1[i1] == t2[i2]) return max(1, x);
            return x;
        }

        if(i2 == 0) {
            int x = find(i1 - 1, i2, t1, t2, dp);
            if(t1[i1] == t2[i2]) return max(1, x);
            return x;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(t1[i1] == t2[i2]) {
            return dp[i1][i2] = 1 + find(i1 - 1, i2 - 1, t1, t2, dp);
        }
        else {
            int left  = find(i1 - 1, i2, t1, t2, dp);
            int right = find(i1, i2 - 1, t1, t2, dp);

            return dp[i1][i2] = max(left, right);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return find(n - 1, m - 1, text1, text2, dp);
    }
};