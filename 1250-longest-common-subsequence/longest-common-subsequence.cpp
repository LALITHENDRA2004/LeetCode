class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m), curr(m);
        
        if(text1[0] == text2[0]) {
            prev[0] = 1;
        }

        for(int i = 1 ; i < m ; i++) {
            if(text1[0] == text2[i]) prev[i] = max(1, prev[i - 1]);
            else prev[i] = prev[i - 1]; 
        } 

        for(int i = 1 ; i < n ; i++) {

            if(text1[i] == text2[0]) curr[0] = max(1, prev[0]);
            else curr[0] = prev[0];
            
            for(int j = 1 ; j < m ; j++) {
                if(text1[i] == text2[j]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    int left  = prev[j];
                    int right = curr[j - 1];

                    curr[j] = max(left, right);
                }
            }

            prev = curr;
        }

        return prev[m - 1];
    }
};