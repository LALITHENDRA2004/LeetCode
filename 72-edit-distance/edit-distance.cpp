class Solution {
public:
    int find(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == t[j - 1]) {
            return find(i - 1, j - 1, s, t, dp);
        }

        int insert = 1 + find(i, j - 1, s, t, dp);
        int deletee = 1 + find(i - 1, j, s, t, dp);
        int replace = 1 + find(i - 1, j - 1, s, t, dp);

        int ans = min(insert, min(deletee, replace));
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return find(n, m, word1, word2, dp);
    }
};