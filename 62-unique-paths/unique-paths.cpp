class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev2(n, 1);
        vector<int> prev1(n, 1);
        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                prev1[j] = prev2[j] + prev1[j - 1];
                prev2 = prev1;
            }
        }
        return prev1[n - 1];
        
    }
};