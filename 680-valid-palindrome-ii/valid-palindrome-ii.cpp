class Solution {
public:
    bool checkPal(string &s, int st, int en) {
        for(int i = st, j = en ; i < j ; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i = 0, j = s.size() - 1 ; i < j ; i++, j--) {
            if(s[i] != s[j]) {
                bool ignoreI = checkPal(s, i + 1, j);
                bool ignoreJ = checkPal(s, i, j - 1);

                return ignoreI || ignoreJ;
            }
        }
        return true;
    }
    // aabbdcc
};