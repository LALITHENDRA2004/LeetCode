class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for(int i = 1 ; i < word.size() ; i++) {
            ans += word[i - 1] == word[i] ? 1 : 0;
        }
        return ans;
    }
};