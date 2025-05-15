class Solution {
public:
    vector<string> find(vector<string>& words, vector<int>& groups, int i) {
        if(i == -1) return {};
        vector<string> ans;
        int flag = groups[i] ^ 1;
        for(int j = i ; j < groups.size() ; j++) {
            if(flag + groups[j] == 1) {
                ans.push_back(words[j]);
                flag = flag ^ 1;
            } 
        }
        return ans;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int fo = -1, fz = -1;
        for(int i = 0 ; i < groups.size() ; i++) {
            if(fo == -1 && groups[i] == 1) fo = i;
            if(fz == -1 && groups[i] == 0) fz = i;
            if(fo != -1 && fz != -1) break;
        }

        int first = find(words, groups, fo).size();
        int second = find(words, groups, fz).size();

        if(first > second) return find(words, groups, fo);
        return find(words, groups, fz);

    }
};